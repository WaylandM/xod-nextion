node {
    void evaluate(Context ctx) {

        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `EasyNex` class instance
        auto eznex = getValue<input_DEV>(ctx);

        uint8_t triggerID = eznex -> NextionListen();

        if (triggerID < 255) {
            emitValue<output_TrigID>(ctx, triggerID);
            emitValue<output_Trig>(ctx, 1);
        }
        emitValue<output_Done>(ctx, 1);
    }

}
