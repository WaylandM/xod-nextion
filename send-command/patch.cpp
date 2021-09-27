node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
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

        eznex -> writeStr(cStringCmd);
        emitValue<output_Done>(ctx, 1);
    }
}

