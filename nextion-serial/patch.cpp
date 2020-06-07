// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/Seithan/EasyNextionLibrary"

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

    Type eznex = new (state->mem) EasyNex(Serial);
    // Begin the EasyNex object with user specified Baud rate
    eznex->begin(getValue<input_BAUD>(ctx));
    emitValue<output_DEV>(ctx, eznex);
}
