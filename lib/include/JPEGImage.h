/* 
 * File:   JPEGImage.h
 * Author: arnaudboeglin
 *
 * Created on July 17, 2009, 6:13 PM
 */

#ifndef _JPEGIMAGE_H
#define	_JPEGIMAGE_H

#include "Image.h"

#include <string>

namespace ke {

    class JPEGImage : public ke::Image{

    public:

        JPEGImage(std::string path);
        virtual ~JPEGImage();

    private:

    };

}

#endif	/* _JPEGIMAGE_H */

