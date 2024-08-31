# KBD firmware

## How to build

## 1. Setting Up Your QMK Environment

Please see https://docs.qmk.fm/#/newbs_getting_started and set up 1 to 3.

## 2. Getting source files

Please get source files of `qmk/qmk_firmware` and `vial-kb/vial-qmk`
```sh
make git-submodule
```

## 3. Building firmwares

### for VIA

```sh
make qmk-clean
kb=crkbd make qmk-init
kb=crkbd kr=rev3/rp2040 km=custom make qmk-compile
```
A built data will be stored on `keyboards/crkbd/qmk/qmk_firmware/.build`\
Please change `kb`, `kr` and `km` when build other.

### for Vial
```sh
make vial-qmk-clean
kb=crkbd make vial-qmk-init
kb=crkbd kr=rev3/rp2040 km=custom make vial-qmk-compile
```
A built data will be stored on `keyboards/crkbd/vial-kb/vial-qmk/.build`\
Please change `kb`, `kr` and `km` when build other.

#### 4-Layers Display 

![switching-layer](https://github.com/user-attachments/assets/9bef5219-92a9-4c2c-80a0-f7b7d186ebd1)