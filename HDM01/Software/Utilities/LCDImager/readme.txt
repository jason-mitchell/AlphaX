LCD Imager.
by B. Mitchell. 
v1.0 - 27/09/2002
v2.0 - 08/08/2004
v2.1 - 13/12/2008

 LCD Imager is a 32-bit Windows utility that allows the user
 to create monochrome images and convert bitmap files to a 
 binary format suitable for Toshiba T6963-based displays and
 vice versa.

 Images can be of any size, provided that the width and height can be
 divided by 8 without leaving a remainder. The width and height of an
 image is determined by manually specifying them under OPTIONS or by
 opening a monochrome bitmap file. Although colour bitmaps are accepted,
 it is recommended that only monochrome bitmaps be used, as any colour
 that is neither black or white is automatically masked prior to
 converting.
 
 Since this application was designed to aid development with monochrome

 LCD panels, only pixel plotting (black) and unplotting (white) is currently
 supported. To place a pixel in the user editing area, simply click on the
 left button of the mouse. Conversely, a pixel can be set to white or erased
 by clicking with the right button. The Image can be previewed by clicking
 OPTIONS/IMAGE PREVIEW at any time. 

 Binary images previously created by LCD Imager can be opened and
 edited if necessary or converted to Windows compatible bitmaps.
 Any image created or manipulated under LCD Imager can be saved
 as a standard monochrome bitmap (*.bmp file), a binary image 
 (*.dat) suitable for writing directly to EPROMs for example, or as
 an assembly source listing (*.ASM) so that an assembler tool can
 automatically allocate where the data should reside on a target
 system. LCD Imager supports various Define Byte directives for
 a wide variety of cross assemblers (e.g DB, DC.B, DEFB, DFB etc.).



