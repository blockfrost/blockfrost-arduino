with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "blockfrost-arduino";
  buildInputs = [
    platformio
    (python3.withPackages (ps: [ ps.cryptography ] ))
    doxygen
  ];
  shellHook = ''
    echo "# To build and upload an example:"
    echo "pio run"
    echo "pio run --target upload"
    echo ""
    echo "# To test:"
    echo "pio test -c platformio-test.ini -e native"
  '';
}
