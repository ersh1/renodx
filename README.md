[![CMake on Windows](https://github.com/clshortfuse/renodx/actions/workflows/cmake-windows.yml/badge.svg)](https://github.com/clshortfuse/renodx/actions/workflows/cmake-windows.yml) [![Discord](https://img.shields.io/discord/1161035767917850784?logo=discord&logoColor=%23fff&label=Discord&labelColor=%235865F2)](https://discord.gg/5WZXDpmbpP)


# renodx
RenoDX, short for "Renovation Engine for DirectX Games", is a toolset to mod games. Currently it can replace shaders, inject buffers, add overlays, upgrade swapchains, upgrade texture resources, and write user settings to disks. Because RenoDX uses Reshade's add-on system, compatibility is expected to be pretty wide. Using Reshade simplies all the hook necessary to tap into DirectX without worrying about patching version-specific exe files.


# Modded Games

| Name                     | Mods                                                                                                                                                                                                      | Mod Page                                                                                 | Latest Build                                                                                            | Status                                                     |
| :----------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------ | :--------------------------------------------------------- |
| Batman: Arkham Knight    | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fbatmanak?type=file&extension=hlsl&label=Shaders)         | [Nexus Mods](https://www.nexusmods.com/batmanarkhamknight/mods/1509)                     | [renodx-batmanak.addon64](https://clshortfuse.github.io/renodx/renodx-batmanak.addon64)                 | :white_check_mark:                                         |
| Cyberpunk 2077           | ![HDR](https://img.shields.io/badge/HDR-Fix-green) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fcp2077?type=file&extension=hlsl&label=Shaders)          | [Nexus Mods](https://www.nexusmods.com/cyberpunk2077/mods/13912)                         | [renodx-cp2077.addon64](https://clshortfuse.github.io/renodx/renodx-cp2077.addon64)                     | :white_check_mark:                                         |
| Deus Ex: Mankind Divided | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Ffallout4?type=file&extension=hlsl&label=Shaders)         | [Nexus Mods](https://www.nexusmods.com/deusexmankinddivided/mods/28)                     | [renodx-dxmd.addon64](https://clshortfuse.github.io/renodx/renodx-dxmd.addon64)                         | :white_check_mark:                                         |
| Dying Light 2            | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fdyinglight2?type=file&extension=hlsl&label=Shaders)      |                                                                                          | [renodx-dyinglight2.addon64](https://clshortfuse.github.io/renodx/renodx-dyinglight2.addon64)           | :construction:                                             |
| Fallout 4                | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fdxmd?type=file&extension=hlsl&label=Shaders)             | [Nexus Mods](https://www.nexusmods.com/fallout4/mods/81123)                              | [renodx-fallout4.addon64](https://clshortfuse.github.io/renodx/renodx-fallout4.addon64)                 | :white_check_mark:                                         |
| Hades                    | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fhades?type=file&extension=hlsl&label=Shaders)            |                                                                                          | [renodx-hades.addon64](https://clshortfuse.github.io/renodx/renodx-hades.addon64)                       | :construction:                                             |
| Hi-Fi Rush               | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fhifirush?type=file&extension=hlsl&label=Shaders)         | [Nexus Mods](https://www.nexusmods.com/hifirush/mods/24)                                 | [renodx-hifirush.addon64](https://clshortfuse.github.io/renodx/renodx-hifirush.addon64)                 | :white_check_mark:                                         |
| Just Cause 4             | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fjustcause4?type=file&extension=hlsl&label=Shaders)       |                                                                                          | [renodx-justcause4.addon64](https://clshortfuse.github.io/renodx/renodx-justcause4.addon64)             | :white_check_mark:                                         |
| L.A. Noire               | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Flanoire?type=file&extension=hlsl&label=Shaders)          | [Nexus Mods](https://www.nexusmods.com/lanoire/mods/6)                                   | [renodx-lanoire.addon32](https://clshortfuse.github.io/renodx/renodx-lanoire.addon32)                   | :white_check_mark:                                         |
| Lost Planet              | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Flanoire?type=file&extension=hlsl&label=Shaders)          | [Nexus Mods](https://www.nexusmods.com/lostplanetextremeconditioncoloniesedition/mods/2) | [renodx-lostplanet.addon32](https://clshortfuse.github.io/renodx/renodx-lostplanet.addon32)             | :white_check_mark:                                         |
| Sea of Stars             | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fseaofstars?type=file&extension=hlsl&label=Shaders)       |                                                                                          | [renodx-seaofstars.addon64](https://clshortfuse.github.io/renodx/renodx-seaofstars.addon64)             | :construction:                                             |
| Sea of Thieves           | ![HDR](https://img.shields.io/badge/HDR-Fix-green) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fseaofthieves?type=file&extension=hlsl&label=Shaders)    |                                                                                          | [renodx-seaofthieves.addon64](https://clshortfuse.github.io/renodx/renodx-seaofthieves.addon64)         | [:skull:](# "No longer supported because Easy Anti-Cheat") |
| Sonic Generations        | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Fsonicgenerations?type=file&extension=hlsl&label=Shaders) |                                                                                          | [renodx-sonicgenerations.addon32](https://clshortfuse.github.io/renodx/renodx-sonicgenerations.addon32) | :construction:                                             |
| Tunic                    | ![HDR](https://img.shields.io/badge/HDR-Add-blue) ![Shaders](https://img.shields.io/github/directory-file-count/clshortfuse/renodx/src%2Fgames%2Ftunic?type=file&extension=hlsl&label=Shaders)            | [Nexus Mods](https://www.nexusmods.com/tunic/mods/8)                                     | [renodx-tunic.addon64](https://clshortfuse.github.io/renodx/renodx-tunic.addon64)                       | :white_check_mark:                                         |

# Utilities

* [renodx-devkit.addon64](https://clshortfuse.github.io/renodx/renodx-devkit.addon64)

