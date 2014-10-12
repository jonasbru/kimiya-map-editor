/*
 * File:   PNGImage.h
 * Author: jonas
 *
 * Created on 17 juillet 2009, 18:44
 */

#ifndef _PNGIMAGE_H
#define	_PNGIMAGE_H

#include "Image.h"

namespace ke {

class PNGImage : public ke::Image {

public:
    
    PNGImage(std::string path);
    PNGImage(const ke::PNGImage& orig);
    virtual ~PNGImage();

private:

    void GetPNGtextureInfo(int color_type);
    
};

}

#endif	/* _PNGIMAGE_H */

