/**********************************************************************
 * File:        imgs.h  (Formerly images.h)
 * Description: Header file for IMAGE member functions.
 * Author:      Ray Smith
 * Created:     Mon Jun 11 15:32:53 BST 1990
 *
 * (C) Copyright 1990, Hewlett-Packard Ltd.
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 ** http://www.apache.org/licenses/LICENSE-2.0
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 *
 **********************************************************************/

#ifndef           IMGS_H
#define           IMGS_H

#include          "img.h"
#include          "varable.h"

extern INT_VAR_H (image_default_resolution, 300, "Image resolution dpi");

INT32 check_legal_image_size(                     //get rest of image
                             INT32 x,             //x size required
                             INT32 y,             //ysize required
                             INT8 bits_per_pixel  //bpp required
                            );
                                 //copy rectangle
extern DLLSYM void copy_sub_image(IMAGE *source,     //source image
                                  INT32 xstart,      //start coords
                                  INT32 ystart,
                                  INT32 xext,        //extent to copy
                                  INT32 yext,
                                  IMAGE *dest,       //destination image
                                  INT32 xdest,       //destination coords
                                  INT32 ydest,
                                  BOOL8 adjust_grey  //shift to new bpp
                                 );
                                 //enlarge rectangle
extern DLLSYM void enlarge_sub_image(IMAGE *source,     //source image
                                     INT32 xstart,      //scaled start coords
                                     INT32 ystart,
                                     IMAGE *dest,       //destination image
                                     INT32 xdest,       //dest coords
                                     INT32 ydest,
                                     INT32 xext,        //destination extent
                                     INT32 yext,
                                     INT32 scale,       //scale factor
                                     BOOL8 adjust_grey  //shift to new bpp
                                    );
                                 //reduce rectangle
extern DLLSYM void fast_reduce_sub_image(IMAGE *source,     //source image
                                         INT32 xstart,      //start coords
                                         INT32 ystart,
                                         INT32 xext,        //extent to copy
                                         INT32 yext,
                                         IMAGE *dest,       //destination image
                                         INT32 xdest,       //destination coords
                                         INT32 ydest,
                                         INT32 scale,       //reduction factor
                                         BOOL8 adjust_grey  //shift to new bpp
                                        );
                                 //reduce rectangle
extern DLLSYM void reduce_sub_image(IMAGE *source,     //source image
                                    INT32 xstart,      //start coords
                                    INT32 ystart,
                                    INT32 xext,        //extent to copy
                                    INT32 yext,
                                    IMAGE *dest,       //destination image
                                    INT32 xdest,       //destination coords
                                    INT32 ydest,
                                    INT32 scale,       //reduction factor
                                    BOOL8 adjust_grey  //shift to new bpp
                                   );
extern DLLSYM void invert_image(              /*invert the image */
                                IMAGE *image  /*image ot invert */
                               );
                                 //bias rectangle
extern DLLSYM void bias_sub_image(IMAGE *source,  //source image
                                  INT32 xstart,   //start coords
                                  INT32 ystart,
                                  INT32 xext,     //extent to copy
                                  INT32 yext,
                                  UINT8 bias      //number to add
                                 );
                                 //copy rectangle
extern DLLSYM void starbase_to_normal(IMAGE *source,       //source image
                                      INT32 xstart,        //start coords
                                      INT32 ystart,
                                      INT32 xext,          //extent to copy
                                      INT32 yext,
                                      IMAGE *dest,         //destination image
                                      INT32 xdest,         //destination coords
                                      INT32 ydest,
                                      BOOL8 preserve_grey  //shift to new bpp
                                     );
#endif
