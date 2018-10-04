# GxVBassPreAmp.lv2
Analog Simulation of the 1984 (*) Vox Venue Bass 100 Pre Amp Section.

![GxVBassPreAmp](https://github.com/brummer10/GxVBassPreAmp.lv2/raw/master/GxVBassPreAmp.png)

###### BUILD DEPENDENCY’S 

the following packages are needed to build GxVBassPreAmp:

- libc6-dev
- libcairo2-dev
- libx11-dev
- x11proto-dev
- lv2-dev

note that those packages could have different, but similar names 
on different distributions. There is no configure script, 
make will simply fail when one of those packages isn't found.

## BUILD 

$ make install

will install into ~/.lv2

$ sudo make install

will install into /usr/lib/lv2

(*) Other product names modeled in this software are trademarks 
of their respective companies that do not endorse and are not associated 
or affiliated with this simulation. Vox is trademark or trade name 
of other manufacturer and was used merely to identify the product 
whose sound was reviewed in the creation of this product. 
All other trademarks are the property of their respective holders.
