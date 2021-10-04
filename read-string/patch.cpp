node {
    CStringView view;
    char* cStringOut;

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

        String str = eznex -> readStr(cString);
        int strLen = str.length() + 1;
        cStringOut = new char[strLen];

        str.toCharArray(cStringOut, strLen);

        view=CStringView(cStringOut);

        emitValue<output_String>(ctx, XString(&view));
        emitValue<output_Done>(ctx, 1);
    }

}

