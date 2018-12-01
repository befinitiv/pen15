$fn=128;

include <consts.scad>;

//This realized the clip+top of the pen
//
//Print with regular PLA


translate([0, CLIP_L/2, CLIP_Z/2])difference() {
    cube([CLIP_X, CLIP_L, CLIP_Z], center=true);
    cube([2*FIL_D, 2*N*FIL_D, CLIP_Z+2], center=true);
    #translate([0,0,(CLIP_Z-FIBER_CLAMP_Z)/2])cube([FIBER_CLAMP_X, 2*N*FIL_D, FIBER_CLAMP_Z], center=true);
}


CAP_D = D_I;
CLIP_OFFSET_Z = 3;
translate([0, -CAP_H/2, CLIP_Z/2])cube([CLIP_X, CAP_H, CLIP_Z], center=true);
translate([0,0,CAP_D/2+CLIP_OFFSET_Z])rotate([90,0,0])cylinder(h=CAP_H, d=CAP_D);


translate([0,CLIP_L+2/2, CLIP_Z/2/2])cube([CLIP_X, 2, CLIP_Z/2], center=true);
