The computer algebra system Maxima is used to generate the arm-system tables.

We are using Maxima 5.42.0

Install maxima including the GUI vxMaxima. Typically it will install to C:\maxima-5.41.0a

When starting vxMaxima, it will run in the catalog where it is installed. In order to 
build the arm-system tables the working directory must be changed to the root directory 
of the project. An example of the path to the SwingDoorPlatform project would be:

c:\Users\sejgr\Documents\SwingDoorPlatform

With this setup, 
 - In vxMaxima, press the kogg-wheel symbol to open vxMaxima configuration.
 - In the displayed pop-up window, press "Startup commands" symbol
 - In the lower window, insert the following;
   load("operatingsystem");
   chdir("..");
   chdir("..");
   chdir("Users");
   chdir("sejgr");
   chdir("Documents");
   chdir("SwingDoorPlatform");
 
