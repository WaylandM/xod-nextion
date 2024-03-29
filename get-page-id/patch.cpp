
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `EasyNex` class instance
        auto eznex = getValue<input_DEV>(ctx);

        emitValue<output_Curr>(ctx, eznex -> currentPageId);
        emitValue<output_Prev>(ctx, eznex -> lastCurrentPageId);
        emitValue<output_Done>(ctx, 1);
    }
}

