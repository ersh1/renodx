/*
 * Copyright (C) 2023 Carlos Lopez
 * SPDX-License-Identifier: MIT
 */

#define ImTextureID ImU64

#define DEBUG_LEVEL_0

#include <embed/0x00E2BDB5.h>
#include <embed/0x11044178.h>
#include <embed/0x40CB7397.h>
#include <embed/0x48A33894.h>
#include <embed/0x48BDD659.h>
#include <embed/0x7FF6EC9E.h>
#include <embed/0x84EF14ED.h>
#include <embed/0xAC144B8D.h>
#include <embed/0xDA65F8ED.h>
#include <embed/0xEDC9A10D.h>

#include <deps/imgui/imgui.h>
#include <include/reshade.hpp>

#include "../../mods/shader.hpp"
#include "../../mods/swapchain.hpp"
#include "../../utils/user_setting.hpp"
#include "./shared.h"

namespace {

renodx::mods::shader::CustomShaders custom_shaders = {
  CustomShaderEntry(0x7FF6EC9E),  // Final
  CustomShaderEntry(0x11044178),  // Film Grain
  CustomShaderEntry(0x48A33894),  // Chromatic Aberration
  CustomShaderEntry(0xDA65F8ED),  // Sharpen
  CustomShaderEntry(0x84EF14ED),  // TemporalAA
  CustomShaderEntry(0x00E2BDB5),  // TemporalAA Off
  CustomShaderEntry(0x40CB7397),  // LUT + Overlay
  CustomShaderEntry(0xEDC9A10D),  // LUT
  CustomShaderEntry(0x48BDD659),  // Lens Flare
  CustomShaderEntry(0xAC144B8D)   // BloomExp
};

ShaderInjectData shader_injection;

// clang-format off
renodx::utils::user_settings::UserSettings user_settings = {
  new renodx::utils::user_settings::UserSetting {
    .key = "toneMapType",
    .binding = &shader_injection.toneMapType,
    .value_type = renodx::utils::user_settings::UserSettingValueType::INTEGER,
    .default_value = 3.f,
    .can_reset = false,
    .label = "Tone Mapper",
    .section = "Tone Mapping",
    .tooltip = "Sets the tone mapper type",
    .labels = {"Vanilla", "None", "ACES", "RenoDRT"}
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "toneMapPeakNits",
    .binding = &shader_injection.toneMapPeakNits,
    .default_value = 1000.f,
    .can_reset = false,
    .label = "Peak Brightness",
    .section = "Tone Mapping",
    .tooltip = "Sets the value of peak white in nits",
    .min = 48.f,
    .max = 4000.f
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "toneMapGameNits",
    .binding = &shader_injection.toneMapGameNits,
    .default_value = 203.f,
    .can_reset = false,
    .label = "Game Brightness",
    .section = "Tone Mapping",
    .tooltip = "Sets the value of 100%% white in nits",
    .min = 48.f,
    .max = 500.f
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "toneMapUINits",
    .binding = &shader_injection.toneMapUINits,
    .default_value = 203.f,
    .can_reset = false,
    .label = "UI Brightness",
    .section = "Tone Mapping",
    .tooltip = "Sets the brightness of UI and HUD elements in nits",
    .min = 48.f,
    .max = 500.f
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "toneMapGammaCorrection",
    .binding = &shader_injection.toneMapGammaCorrection,
    .value_type = renodx::utils::user_settings::UserSettingValueType::BOOLEAN,
    .can_reset = false,
    .label = "Gamma Correction",
    .section = "Tone Mapping",
    .tooltip = "Emulates a 2.2 EOTF (use with HDR or sRGB)",
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeExposure",
    .binding = &shader_injection.colorGradeExposure,
    .default_value = 1.f,
    .label = "Expsoure",
    .section = "Color Grading",
    .max = 10.f,
    .format = "%.2f"
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeHighlights",
    .binding = &shader_injection.colorGradeHighlights,
    .default_value = 50.f,
    .label = "Highlights",
    .section = "Color Grading",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeShadows",
    .binding = &shader_injection.colorGradeShadows,
    .default_value = 50.f,
    .label = "Shadows",
    .section = "Color Grading",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeContrast",
    .binding = &shader_injection.colorGradeContrast,
    .default_value = 50.f,
    .label = "Contrast",
    .section = "Color Grading",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeSaturation",
    .binding = &shader_injection.colorGradeSaturation,
    .default_value = 50.f,
    .label = "Saturation",
    .section = "Color Grading",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "colorGradeLUTStrength",
    .binding = &shader_injection.colorGradeLUTStrength,
    .default_value = 100.f,
    .label = "LUT Strength",
    .section = "Color Grading",
    .max = 100.f,
    .parse = [](float value) { return value * 0.01f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxBloom",
    .binding = &shader_injection.fxBloom,
    .default_value = 50.f,
    .label = "Bloom",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxLensFlare",
    .binding = &shader_injection.fxLensFlare,
    .default_value = 50.f,
    .label = "Lens Flare",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxSharpen",
    .binding = &shader_injection.fxSharpen,
    .default_value = 50.f,
    .label = "Sharpen",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxChromaticAberration",
    .binding = &shader_injection.fxChromaticAberration,
    .default_value = 50.f,
    .label = "Chromatic Aberration",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxVignette",
    .binding = &shader_injection.fxVignette,
    .default_value = 50.f,
    .label = "Vignette",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  },
  new renodx::utils::user_settings::UserSetting {
    .key = "fxFilmGrain",
    .binding = &shader_injection.fxFilmGrain,
    .default_value = 50.f,
    .label = "Film Grain",
    .section = "Effects",
    .max = 100.f,
    .parse = [](float value) { return value * 0.02f; }
  }
};

// clang-format on

void OnPresetOff() {
  renodx::utils::user_settings::UpdateUserSetting("toneMapType", 0.f);
  renodx::utils::user_settings::UpdateUserSetting("toneMapPeakNits", 203.f);
  renodx::utils::user_settings::UpdateUserSetting("toneMapGameNits", 203.f);
  renodx::utils::user_settings::UpdateUserSetting("toneMapUINits", 203.f);
  renodx::utils::user_settings::UpdateUserSetting("toneMapGammaCorrection", 0);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeExposure", 1.f);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeHighlights", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeShadows", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeContrast", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeSaturation", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("colorGradeLUTStrength", 100.f);
  renodx::utils::user_settings::UpdateUserSetting("fxBloom", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("fxLensFlare", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("fxSharpen", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("fxChromaticAberration", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("fxVignette", 50.f);
  renodx::utils::user_settings::UpdateUserSetting("fxFilmGrain", 50.f);
}

}  // namespace

// NOLINTBEGIN(readability-identifier-naming)

extern "C" __declspec(dllexport) const char* NAME = "RenoDX";
extern "C" __declspec(dllexport) const char* DESCRIPTION = "RenoDX for Deus Ex: Mankind Divided";

// NOLINTEND(readability-identifier-naming)

BOOL APIENTRY DllMain(HMODULE h_module, DWORD fdw_reason, LPVOID lpv_reserved) {
  switch (fdw_reason) {
    case DLL_PROCESS_ATTACH:
      if (!reshade::register_addon(h_module)) return FALSE;
      // renodx::mods::swapchain::swap_chain_upgrade_targets.push_back(
      //   {reshade::api::format::r10g10b10a2_unorm, reshade::api::format::r16g16b16a16_float}
      // );
      // renodx::mods::swapchain::swap_chain_upgrade_targets.push_back(
      //   {reshade::api::format::r11g11b10_float, reshade::api::format::r16g16b16a16_float}
      // );
      renodx::mods::swapchain::swap_chain_upgrade_targets.push_back(
        {//
         .old_format = reshade::api::format::r8g8b8a8_unorm_srgb,
         .new_format = reshade::api::format::r16g16b16a16_float
        }
      );
      renodx::mods::swapchain::swap_chain_upgrade_targets.push_back(
        {//
         .old_format = reshade::api::format::r8g8b8a8_unorm,
         .new_format = reshade::api::format::r16g16b16a16_float,
         .index = 0
        }
      );

      break;
    case DLL_PROCESS_DETACH:
      reshade::unregister_addon(h_module);
      break;
  }

  renodx::utils::user_settings::Use(fdw_reason, &user_settings, &OnPresetOff);
  renodx::mods::swapchain::Use(fdw_reason);
  renodx::mods::shader::Use(fdw_reason, custom_shaders, &shader_injection);

  return TRUE;
}
