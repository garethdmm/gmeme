all: 
	g++ -g -O2 -Wall -W -pthread -I/usr/include/ImageMagick -L/usr/lib -Wl,-Bsymbolic-functions -L/usr/lib/X11 -L/usr/lib -lMagick++ -lMagickWand -lMagickCore -llcms -ltiff -lfreetype -ljpeg -lXext -lSM -lICE -lX11 -lXt -lbz2 -lz -lm -lgomp -lpthread main.cc meme.cc -o gmeme
