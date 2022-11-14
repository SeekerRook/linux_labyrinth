ffmpeg -r 1 -i video.mp4 -r 1 "images/%03d.png";


cp flag.png images/012.png ;

ffmpeg -framerate 30 -pattern_type glob -i 'images/*.png'   -c:v libx264 -pix_fmt yuv420p out.mp4;

xdg-open out.mp4
