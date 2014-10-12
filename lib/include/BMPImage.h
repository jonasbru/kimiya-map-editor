/* 
 * File:   BMPImage.h
 * Author: arnaudboeglin
 *
 * Created on July 16, 2009, 3:25 PM
 */

#ifndef _BMPIMAGE_H
#define	_BMPIMAGE_H

#include "Image.h"

enum{
    /* BMP compression type constants */
    BI_RGB          = 0,
    BI_RLE8         = 1,
    BI_RLE4         = 2,
    BI_BITFIELDS    = 3,

    /* RLE byte type constants */
    RLE_COMMAND     = 0,
    RLE_ENDOFLINE   = 0,
    RLE_ENDOFBITMAP = 1,
    RLE_DELTA       = 2,
};

typedef enum{
	BMP_WIN,
	BMP_OS2,
} os_type_e;

namespace ke {

    class BMPImage : public ke::Image {

    public:

        BMPImage(std::string path);
        ~BMPImage();

    private:
        
        unsigned short FH_type;
        unsigned int FH_size;
        int FH_reserved;
        unsigned int FH_offset_infos;

        unsigned int IH_header_size;
        unsigned short IH_count_of_plane;
        unsigned int IH_compression_value;
        unsigned int IH_img_size;
        unsigned int IH_horizontal_resolution;
        unsigned int IH_vertical_resolution;
        unsigned int IH_count_of_color;
        unsigned int IH_count_of_important_color;

        void readBMP1Bit(std::ifstream &is, GLubyte *colormap, os_type_e os_type);
        void readBMP4Bits(std::ifstream &is, GLubyte *colormap, os_type_e os_type);
        void readBMP8Bits(std::ifstream &is, GLubyte *colormap, os_type_e os_type);
        void readBMP24Bits(std::ifstream &is);
        void readBMP32Bits(std::ifstream &is);
        void readBMP8BitsRLE(std::ifstream &is, GLubyte *colormap);
        void readBMP4BitsRLE(std::ifstream &is, GLubyte *colormap);
        void readBMPFile(const char *filename);

    };

}

#endif	/* _BMPIMAGE_H */

