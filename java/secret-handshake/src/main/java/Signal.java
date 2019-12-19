enum Signal {
   WINK(0b0001)
,  DOUBLE_BLINK(0b0010)
,  CLOSE_YOUR_EYES(0b0100)
,  JUMP(0b1000)
;

   final int value;
   
   Signal(int value) {
      this.value = value;
   }
}
