// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/EasyNextionLibraryXOD"

//Include C++ libraries
{{#global}}
#include <EasyNextionLibrary.h>
{{/global}}


struct State {
    uint8_t mem[sizeof(EasyNex)];
};

// Define our custom type as a pointer on the class instance.
using Type = EasyNex*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type eznex = new (state->mem) EasyNex(Serial);

    // Begin the EasyNex object with a baudrate of 9600
    eznex->begin(9600);

    emitValue<output_DEV>(ctx, eznex);


}
