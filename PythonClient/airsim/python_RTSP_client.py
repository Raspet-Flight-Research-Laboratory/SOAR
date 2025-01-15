import airsim
import cv2
import subprocess
import numpy as np

# Initialize AirSim client
client = airsim.MultirotorClient()
client.confirmConnection()

# GStreamer pipeline for UDP streaming
gst_command = [
    "gst-launch-1.0",
    "fdsrc",
    "!", "videoparse", "format=rgb", "width=1280", "height=720", "framerate=30/1",
    "!", "videoconvert",
    "!", "x264enc", "tune=zerolatency", 
    "!", "rtph264pay", "config-interval=1",
    "!", "udpsink", "host=127.0.0.1", "port=5600", "sync=true"
]
process = subprocess.Popen(gst_command, stdin=subprocess.PIPE)

'''# FFmpeg command
ffmpeg_command = [
    "ffmpeg", "-re", "-f", "rawvideo", "-pix_fmt", "bgr24", "-s", "1280x720",
    "-i", "-", "-c:v", "libx264", "-preset", "ultrafast", "-tune", "zerolatency",
    "-f", "mpegts", "udp://127.0.0.1:5600"
]
process = subprocess.Popen(ffmpeg_command, stdin=subprocess.PIPE)'''
try:
    while True:
        # Capture AirSim camera image
        response = client.simGetImage("1", airsim.ImageType.Scene)
        if response:
            # Convert to OpenCV format
            img = cv2.imdecode(airsim.string_to_uint8_array(response), cv2.IMREAD_COLOR)
            if img is not None:
                # Resize image to match GStreamer settings
                img_resized = cv2.resize(img, (1280, 720))
                process.stdin.write(img_resized.tobytes())
        else:
            print("No image received from AirSim.")
finally:
    process.stdin.close()
    process.wait()
