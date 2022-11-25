# Download video from youtube using youtube-dl
youtube-dl  https://youtu.be/fX5qLlrE7UY

#convert video to mp4 
ffmpeg -i *.mkv video.mp4 

#remove old file
rm *.mkv

# create images folder 
mkdir images

# split the video insto images using ffmpeg
ffmpeg -r 1 -i video.mp4 -r 1 "images/%03d.png" 


#open the images directory wit the default program(file explorer)
xdg-open images

