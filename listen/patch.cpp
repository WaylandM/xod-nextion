
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;
    // Get a pointer to the `EasyNex` class instance
    auto eznex = getValue<input_DEV>(ctx);
    eznex -> NextionListen();
}
