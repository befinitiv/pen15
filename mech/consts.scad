STRIPE_X = 3.4; //width of the LED stripe pcb
STRIPE_Y = 48.5; //length of LED stripe pcb
STRIPE_Z = 0.6; //pcb thickness of LED stripe pcb
LED_X=2; //edge length of LED (assumed to be square)
LED_Z = 1; //LED height above PCB

FIL_D = 0.25; //fiber diameter
NOZ_D = 0.4; //nozzle diameter
CLIP_Z = 5; //height of clip
N = 64; //number of fibers

D_I = 11.6; //inner diameter of pen
D_O = D_I+4*NOZ_D; //outer diameter of pen

CLIP_X = 2*FIL_D+4*NOZ_D;
CLIP_L = 2*N*FIL_D+4*NOZ_D;

CAP_H = 3; //height of cap cylinder attached to clip

PEN_UPPER_Z = 60; //height of upper pen part 
PEN_LOWER_BODY_Z = 60; //height of the cylindrical part
PEN_LOWER_TIP_Z = 20; //height of the tip cone

FIBER_CLAMP_Z = 2;
FIBER_CLAMP_X = 1.2;

STRIPE_JOINER_Z = 3; //height of the 4stripe joiner
