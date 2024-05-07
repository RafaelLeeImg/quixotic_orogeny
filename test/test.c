void print(char const str[]);

void operator_test(void);

void operator_test(void) {
  // ~1u == 0xfffffffe
  // ~1 == 0xfffffffe
  // ~1L == 0xfffffffe
  // ~1uL == 0xfffffffe
  // ~1L < 0
  // ~1uL >= 0

  if (~1u == 0xfffffffe) {
    print("~1u == 0xfffffffe\n");
  } else {
    print("~1u != 0xfffffffe\n");
  }

  if (~1 == 0xfffffffe) {
    print("~1 == 0xfffffffe\n");
  } else {
    print("~1 != 0xfffffffe\n");
  }

  if (~1L == 0xfffffffe) {
    print("~1L == 0xfffffffe\n");
  } else {
    print("~1L != 0xfffffffe\n");
  }

  if (~1uL == 0xfffffffe) {
    print("~1uL == 0xfffffffe\n");
  } else {
    print("~1uL != 0xfffffffe\n");
  }

  if (~1L >= 0) {
    print("~1L >= 0\n");
  } else {
    print("~1L < 0\n");
  }

  if (~1uL >= 0) {
    print("~1uL >= 0\n");
  } else {
    print("~1uL < 0\n");
  }
}