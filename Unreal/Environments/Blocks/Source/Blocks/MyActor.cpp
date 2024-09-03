#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h" // For math functions

AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyActor::RasDaa1(const FVector Ownship, const FVector Intruder, const FVector OwnshipHeadingSpeed, const FVector IntruderHeadingSpeed, float& StartAngle, float& EndAngle, int32& Alert, FParameters1 Parameters, FParameters1& TestOutParameters)
{

    float IntruderHeading = IntruderHeadingSpeed.X;
    float IntruderSpeed = IntruderHeadingSpeed.Y;

    double a = UKismetMathLibrary::Sin(UKismetMathLibrary::DegreesToRadians(-IntruderHeading));
    double b = UKismetMathLibrary::Cos(UKismetMathLibrary::DegreesToRadians(-IntruderHeading));
    double c = a * Intruder.X + b * Intruder.Y;

    // solve the 2nd order polynomial
    double coeff1, coeff2, coeff3;
    if (a == 0) {
        coeff1 = 1;
        coeff2 = ((-2.0) * Ownship.X) / coeff1;
        coeff3 = (Ownship.X * Ownship.X + (c / b - Ownship.Y) * (c / b - Ownship.Y) - (OwnshipHeadingSpeed.Y * Parameters.Tt) * (OwnshipHeadingSpeed.Y * Parameters.Tt)) / coeff1;
    }
    else if (b == 0) {
        coeff1 = 1;
        coeff2 = ((-2.0) * Ownship.Y) / coeff1;
        coeff3 = (Ownship.Y * Ownship.Y + (c / a - Ownship.X) * (c / a - Ownship.X) - (OwnshipHeadingSpeed.Y * Parameters.Tt) * (OwnshipHeadingSpeed.Y * Parameters.Tt)) / coeff1;
    }
    else {
        coeff1 = 1 + (a / b) * (a / b);
        coeff2 = (2.0) * ((a / b) * (Ownship.Y - c / b) - Ownship.X) / coeff1;
        coeff3 = (Ownship.X * Ownship.X + (Ownship.Y - c / b) * (Ownship.Y - c / b) - (OwnshipHeadingSpeed.Y * Parameters.Tt) * (OwnshipHeadingSpeed.Y * Parameters.Tt)) / coeff1;
    }

    double det_val = (coeff2 / 2) * (coeff2 / 2) - coeff3;

    std::vector<std::vector<double>> crss_pnt(2, std::vector<double>(2));
    if (a == 0 && det_val >= 0) {
        crss_pnt[0][0] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * (-1);
        crss_pnt[1][0] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * 1;
        crss_pnt[0][1] = crss_pnt[1][1] = c / b;
    }
    else if (b == 0 && det_val >= 0) {
        crss_pnt[0][1] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * (-1);
        crss_pnt[1][1] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * 1;
        crss_pnt[0][0] = crss_pnt[1][0] = c / a;
    }
    else if (det_val >= 0) {
        crss_pnt[0][0] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * (-1);
        crss_pnt[1][0] = (-1.0) * (coeff2 / 2) + sqrt(det_val) * 1;
        crss_pnt[0][1] = c / b - a / b * crss_pnt[0][0];
        crss_pnt[1][1] = c / b - a / b * crss_pnt[1][0];
    }
    else {
        crss_pnt = { { NAN, NAN }, { NAN, NAN } };
    }

    std::vector<double> crss_pnt_ang(2);
    if (std::all_of(crss_pnt.begin(), crss_pnt.end(), [](const std::vector<double>& v) { return !std::isnan(v[0]) && !std::isnan(v[1]); })) {
        for (int i = 0; i < 2; ++i) {
            crss_pnt_ang[i] = atan2(crss_pnt[i][1] - Ownship.Y, crss_pnt[i][0] - Ownship.X) * 180.0 / PI;
        }
    }

    double min_crss_pnt_ang = *std::min_element(crss_pnt_ang.begin(), crss_pnt_ang.end());
    double max_crss_pnt_ang = *std::max_element(crss_pnt_ang.begin(), crss_pnt_ang.end());

    // Decision of band color
    double dist_acs = sqrt(pow(Intruder.X - Ownship.X, 2) + pow(Intruder.Y - Ownship.Y, 2));

    // Alert variables: order -> [sst, art, wcb]
    if (dist_acs > Parameters.RCirArt && dist_acs <= Parameters.RCirSst) {
        Alert = 1;
        if (!Parameters.UpdateArtRadius && !Parameters.UpdateArtRadiusCheck) {
            Parameters.UpdateArtRadius = true;
            Parameters.UpdateArtRadiusCheck = true;
        }
        else {
            Parameters.UpdateArtRadius = false;
        }
    }
    // else if (dist_acs > Parameters.RCirWcb && dist_acs <= Parameters.RCirArt) {
    else if (dist_acs <= Parameters.RCirArt) {
        Alert = 2;
    }
    else {
        Alert = 0;
        Parameters.UpdateArtRadiusCheck = false;
    }

    // Calculate ART radius
    if (Parameters.UpdateArtRadius) {
        double del_vel = (-1.0) * (OwnshipHeadingSpeed.Y * IntruderSpeed) * (cos((OwnshipHeadingSpeed.X - IntruderHeading) * PI / 180) + sin((OwnshipHeadingSpeed.X - IntruderHeading) * PI / 180));
        Parameters.RCirArt = Parameters.RCirArt + del_vel * Parameters.RCirArtScale;
        Parameters.UpdateArtRadius = false;
        Parameters.UpdateArtRadiusCheck = true;
    }

    StartAngle = min_crss_pnt_ang;
    EndAngle = max_crss_pnt_ang;
}

FIntersection1 AMyActor::solveLinearSystem1(double a1, double b1, double c1, double a2, double b2, double c2)
{
    FIntersection1 intersection;
    double det = a1 * b2 - a2 * b1;
    if (fabs(det) < 1e-6) {
        intersection.points = { NAN, NAN };
    }
    else {
        intersection.points = { (c1 * b2 - c2 * b1) / det, (a1 * c2 - a2 * c1) / det };
        // intersection.points = {b2/det*c1 + -b1/det*c2, -a2/det*c1 + a1/det*c2};

        intersection.angle = atan2(intersection.points[1], intersection.points[0]) * 180.0 / PI;
    }

    return FIntersection1();
}

TArray<double> AMyActor::findCircleIntersections1(FAircraft1 ownship, FAircraft1 intruder, double radius)
{
    double dx = intruder.dir[0];
    double dy = intruder.dir[1];
    double x0 = intruder.x - ownship.x;
    double y0 = intruder.y - ownship.y;

    double A_circle = dx * dx + dy * dy;
    double B_circle = 2 * (dx * x0 + dy * y0);
    double C_circle = x0 * x0 + y0 * y0 - radius * radius;

    double det = B_circle * B_circle - 4 * A_circle * C_circle;

    TArray<double> circleIntersections;
    if (det < 0) {
        circleIntersections = { NAN, NAN, NAN, NAN };
    }
    else {
        double t1 = (-B_circle + sqrt(det)) / (2 * A_circle);
        double t2 = (-B_circle - sqrt(det)) / (2 * A_circle);

        double intersect1_x = intruder.x + t1 * dx;
        double intersect1_y = intruder.y + t1 * dy;
        double intersect2_x = intruder.x + t2 * dx;
        double intersect2_y = intruder.y + t2 * dy;

        circleIntersections = { intersect1_x, intersect1_y, intersect2_x, intersect2_y };
    }
    return circleIntersections;
}

double AMyActor::calculateAngle1(double x, double y, double origin_x, double origin_y)
{
    return atan2(y - origin_y, x - origin_x) * 180.0 / PI;
}

void AMyActor::findIntersectionWithCircle1(FNewParameters1 Parameter, FAircraft1 ownship, FAircraft1 intruder, double& StartAngle, double& EndAngle, int32& level, double& distance)
{
    // Convert heading angles from degrees to radians and adjust for +y axis as 0 degrees
    ownship.heading = ownship.heading * PI / 180.0;
    intruder.heading = intruder.heading * PI / 180.0;

    // Calculate direction vectors based on heading angles
    ownship.dir = { cos(ownship.heading), sin(ownship.heading) };
    intruder.dir = { cos(intruder.heading), sin(intruder.heading) };

    // Calculate the line equations: (x - x0)/dir_x = (y - y0)/dir_y
    double a1 = ownship.dir[1]; // sin(heading)
    double b1 = -ownship.dir[0]; // -cos(heading)
    double c1 = a1 * ownship.x + b1 * ownship.y;

    double a2 = intruder.dir[1]; // sin(heading)
    double b2 = -intruder.dir[0]; // -cos(heading)
    double c2 = a2 * intruder.x + b2 * intruder.y;

    // Solve the system of equations to find intersection
    FIntersection1 intersection = solveLinearSystem1(a1, b1, c1, a2, b2, c2);

    // Find intersection points with the circle centered at ownship with radius 500
    TArray<double> circleIntersections = findCircleIntersections1(ownship, intruder, Parameter.art);
    double angle1 = calculateAngle1(circleIntersections[0], circleIntersections[1], ownship.x, ownship.y);
    double angle2 = calculateAngle1(circleIntersections[2], circleIntersections[3], ownship.x, ownship.y);

    TArray<double> circleIntersectionAngle = { angle1, angle2 };
    circleIntersectionAngle.Sort();

    if (FMath::Abs(intersection.angle - ownship.heading * 180.0 / PI) < 1) {
        circleIntersectionAngle = { FMath::Min(angle1, angle2), FMath::Max(angle1, angle2) };
    }
    else {
        circleIntersectionAngle = { FMath::Max(angle1, angle2), FMath::Min(angle1, angle2) };
    }
    StartAngle = circleIntersectionAngle[0];
    EndAngle = circleIntersectionAngle[1];
    /* std::vector<double> circleIntersectionAngle = {angle1, angle2};
   std::sort(circleIntersectionAngle.begin(), circleIntersectionAngle.end());

   if (fabs(intersection.angle - ownship.heading * 180.0 / PI) < 1) {
       circleIntersectionAngle = { std::min(angle1, angle2), std::max(angle1, angle2) };
   }
   else {
       circleIntersectionAngle = { std::max(angle1, angle2), std::min(angle1, angle2) };
   }
   circleIntersectionAngles = FVector(circleIntersectionAngle);
   double distance = sqrt(pow(intruder.x - ownship.x, 2) + pow(intruder.y - ownship.y, 2)); */
    distance = FMath::Sqrt(FMath::Pow(intruder.x - ownship.x, 2) + FMath::Pow(intruder.y - ownship.y, 2));

    if (distance > Parameter.sst) {
        level = 0;
    }
    else if (distance <= Parameter.art_for_threatlevel) {
        level = 2;
    }
    else {
        level = 1;
    }
    // Construct and populate the TMap
    // TMap<int32, FArrayWrapper> resultMap;
    // FArrayWrapper arrayWrapper;
    // TArray<double> circleIntersectionTArray;
    // for (double angle : circleIntersectionAngles) {
    //  circleIntersectionTArray.Add(angle);
    // }
    // arrayWrapper.Array = circleIntersectionTArray;
    // resultMap.Add(level, arrayWrapper);
}

void AMyActor::SaveDataIntoCsvFile1(int32 FirstTimeEntry, const FVector LocationInDegreesofOwnship, const FVector LocationInXYZofOwnship, const float HeadingofOwnship, const float SpeedofOwnship, const FVector LocationInDegreesofIntruder, const FVector LocationInXYZofIntruder, const float HeadingofIntruder, const float SpeedofIntruder, float StartAngle, float EndAngle, int32 ThreatLevel)
{
    FString FilePath = FPaths::ProjectDir() + TEXT("\\Data\\datafromunreal.csv");
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    // Ensure the directory exists
    FString DirectoryPath = FPaths::GetPath(FilePath);
    if (!PlatformFile.DirectoryExists(*DirectoryPath)) {
        PlatformFile.CreateDirectory(*DirectoryPath);
    }
    bool bFileExists = PlatformFile.FileExists(*FilePath);

    // Prepare the header line if the file doesn't exist
    FString HeaderLine = TEXT("OwnshipLong, OwnshipLat, Ownshipheight, OwnshipLoc.X, OwnshipLoc.Y, OwnshipLoc.Z, HeadingofOwnship, SpeedofOwnship, IntruderLong, IntruderLat,Intruderheight, IntruderLoc.X, IntruderLoc.Y, IntruderLoc.Z, HeadingofIntruder, SpeedofIntruder, StartAngle, EndAngle, ThreatLevel\n");

    if (!bFileExists) {
        // Write the headerline
        FFileHelper::SaveStringToFile(HeaderLine, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_None);
    }
    else if (FirstTimeEntry == 1) {
        FString EndLine = TEXT("#################, #################, #################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################,#################\n");

        // Write the EndLine
        FFileHelper::SaveStringToFile(EndLine, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
        FirstTimeEntry = 0;
    }

    // Prepare the line to be written
    FString LineToWrite = FString::Printf(TEXT("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d\n"),
                                          LocationInDegreesofOwnship.X,
                                          LocationInDegreesofOwnship.Y,
                                          LocationInDegreesofOwnship.Z,
                                          LocationInXYZofOwnship.X,
                                          LocationInXYZofOwnship.Y,
                                          LocationInXYZofOwnship.Z,
                                          HeadingofOwnship,
                                          SpeedofOwnship,
                                          LocationInDegreesofIntruder.X,
                                          LocationInDegreesofIntruder.Y,
                                          LocationInDegreesofIntruder.Z,
                                          LocationInXYZofIntruder.X,
                                          LocationInXYZofIntruder.Y,
                                          LocationInXYZofIntruder.Z,
                                          HeadingofIntruder,
                                          SpeedofIntruder,
                                          StartAngle,
                                          EndAngle,
                                          ThreatLevel);
    // Write the data
    FFileHelper::SaveStringToFile(LineToWrite, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}
