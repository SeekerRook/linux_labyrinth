
#set passeord=$1
echo $1
cp .snake snake

zip --password $1 snake.zip snake

rm snake
#mv snake nake

