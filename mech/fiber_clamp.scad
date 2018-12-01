include <consts.scad>;

//Clamp that clamps all fibers together.
//This should be glued into the pen's clip from behind (after the fibers are glued into this clamp)
//
//Print this with flexible PLA

difference() {
    cube([FIBER_CLAMP_X+0.2, 2*N*FIL_D, FIBER_CLAMP_Z], center=true);
    cube([2*FIL_D, 2*N*FIL_D-2, CLIP_Z+2], center=true);
}
