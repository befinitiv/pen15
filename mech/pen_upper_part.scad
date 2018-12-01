$fn=128;

include <consts.scad>



module penshaft() {
    difference() {
    cylinder(h=PEN_UPPER_Z, d=D_O);
    cylinder(h=PEN_UPPER_Z, d=D_I);
    }
}


module penclip() {
translate([0, 5, (CLIP_L+CAP_H)/2])cube([CLIP_X+0.04, 10, CLIP_L+CAP_H], center=true);
}

module clip_retainer() {
translate([0,0,CAP_H+0.1])
difference() {
    cylinder(h=1, d=D_I);
    cylinder(h=1, d=D_I-0.3);
}
}


difference() {
union() {
    penshaft();
    clip_retainer();
}
penclip();
}



