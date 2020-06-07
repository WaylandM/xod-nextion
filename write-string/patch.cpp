
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_PUSH>(ctx))
        return;

    // Get a pointer to the `EasyNex` class instance
    auto eznex = getValue<input_DEV>(ctx);
    auto xStringCmd = getValue<input_CMD>(ctx);
    auto xStringText = getValue<input_TEXT>(ctx);

    int N=length(xStringCmd) + 1;
    char cStringCmd[N];
    for(int i=0;i<N;i++)
        cStringCmd[i]=0;
    dump(xStringCmd, cStringCmd);

    N=length(xStringText) + 1;
    char cStringText[N];
    for(int i=0;i<N;i++)
        cStringText[i]=0;
    dump(xStringText, cStringText);

    eznex -> writeStr(cStringCmd, cStringText);
}
