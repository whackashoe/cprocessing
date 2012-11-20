#ifndef CPROCESSING_ALPIECE_
#define CPROCESSING_ALPIECE_

class __ALPiece {
    public:
    void * obj;

    template <class T>
    __ALPiece(T * o) {
        obj = o;
    }
};

#endif