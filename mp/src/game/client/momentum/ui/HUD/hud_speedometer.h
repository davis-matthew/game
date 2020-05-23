#pragma once

#include "hudelement.h"

#include <vgui_controls/EditablePanel.h>

#define SPEEDOMETER_MAX_LABELS 4

class SpeedometerLabel;
class C_MomRunStats;
class C_MomRunEntityData;

typedef CUtlVector<SpeedometerLabel*> SpeedoLabelList;

class CHudSpeedMeter : public CHudElement, public vgui::EditablePanel
{
    DECLARE_CLASS_SIMPLE(CHudSpeedMeter, vgui::EditablePanel);

  public:
    CHudSpeedMeter(const char *pElementName);

    void OnThink() override;
    void Init() override;
    void Reset() override;
    void FireGameEvent(IGameEvent *pEvent) override;
    void ApplySchemeSettings(vgui::IScheme *pScheme) override;
    void OnReloadControls() override;
    void PerformLayout() override;

    SpeedometerLabel *GetLabel(int index) { return m_Labels[index]; }

    SpeedoLabelList *GetLabelOrderListPtr() { return &m_LabelOrderList; }

    void ResetLabelOrder();

  private:
    SpeedometerLabel *m_pAbsSpeedoLabel, *m_pHorizSpeedoLabel, *m_pLastJumpVelLabel, *m_pStageEnterExitVelLabel;

    SpeedoLabelList m_LabelOrderList;

    SpeedometerLabel *m_Labels[SPEEDOMETER_MAX_LABELS];

    C_MomRunStats *m_pRunStats;
    C_MomRunEntityData *m_pRunEntData;

    ConVarRef m_cvarTimeScale;

  protected:
    CPanelAnimationVar(Color, m_bgColor, "BgColor", "Blank");
    CPanelAnimationVar(float, m_fLastJumpVelAlpha, "LastJumpVelAlpha", "0.0");
    CPanelAnimationVar(float, m_fStageVelAlpha, "StageVelAlpha", "0.0");
};

extern CHudSpeedMeter *g_pSpeedometer;