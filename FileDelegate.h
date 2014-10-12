/* 
 * File:   FileDelegate.h
 * Author: jonas
 *
 * Created on 13 novembre 2009, 19:10
 */

#ifndef _FILEDELEGATE_H
#define	_FILEDELEGATE_H

class FileDelegate {

public:

    FileDelegate();
    FileDelegate(const FileDelegate& orig);
    virtual ~FileDelegate();

    void loadAll(std::string filePath);

private:



};

#endif	/* _FILEDELEGATE_H */

