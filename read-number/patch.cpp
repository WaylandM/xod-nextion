
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

    // The node responds only if there is an input pulse
    if (!isInputDirty<input_PUSH>(ctx))
        return;

    // Get a pointer to the `EasyNex` class instance
    auto eznex = getValue<input_DEV>(ctx);
    auto xString = getValue<input_CMD>(ctx);

    int N=length(xString) + 1;
    char cString[N];
    for(int i=0;i<N;i++)
    cString[i]=0;
    dump(xString, cString);

    emitValue<output_NUM>(ctx, eznex -> readNum(cString));
}
