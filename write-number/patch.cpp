node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `EasyNex` class instance
        auto eznex = getValue<input_DEV>(ctx);
        auto xString = getValue<input_CMD>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);
        uint32_t val = getValue<input_VAL>(ctx);
        eznex -> writeNum(cString, val);
        emitValue<output_Done>(ctx, 1);
    }

}

