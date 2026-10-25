W Click GUI — Android project scaffold

IMPORTANT:
This folder is source, not a ready-to-install .geode mod. A real .geode package must be compiled with Geode SDK + Android NDK for the target ABI. This environment does not have the Geode Android toolchain, so it cannot honestly produce a verified installable .geode binary.

Target: Geometry Dash Android 2.2081
Geode target configured: v5.11.2
Build:
  geode sdk install-binaries -p android64
  geode build -p android64

The current starter includes a main-menu W button and settings scaffold. Pause-menu integration and actual frame-perfect automation are not implemented yet.
