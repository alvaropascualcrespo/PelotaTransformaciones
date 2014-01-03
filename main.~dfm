object MainForm: TMainForm
  Left = 183
  Top = 158
  Width = 800
  Height = 479
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 32
    Top = 40
    object Salir1: TMenuItem
      Caption = 'Salir'
      OnClick = Salir1Click
    end
    object NuevaPelota1: TMenuItem
      Caption = 'Nueva Pelota'
      OnClick = NuevaPelota1Click
    end
    object AvanzarMenu: TMenuItem
      Caption = 'Avanzar'
      ShortCut = 65
      OnClick = AvanzarMenuClick
    end
    object ActivaTimer: TMenuItem
      Caption = 'Timer'
      OnClick = ActivaTimerClick
    end
    object Obstaculos1: TMenuItem
      Caption = 'Obstaculos'
      object Triangulo1: TMenuItem
        Caption = 'Triangulo'
        OnClick = Triangulo1Click
      end
      object Circulo1: TMenuItem
        Caption = 'Circulo'
        OnClick = Circulo1Click
      end
      object Elipse1: TMenuItem
        Caption = 'Elipse'
        Hint = 'Elipse'
        OnClick = Elipse1Click
      end
    end
  end
  object Timer: TTimer
    Interval = 10
    OnTimer = TimerTimer
    Left = 168
    Top = 56
  end
end
