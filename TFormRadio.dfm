object FormRadio: TFormRadio
  Left = 342
  Top = 195
  Width = 385
  Height = 180
  Caption = 'Radio'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 104
    Top = 24
    Width = 140
    Height = 13
    Caption = 'Introduce el radio de la pelota'
  end
  object EditRadio: TEdit
    Left = 112
    Top = 56
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object btnAceptarRadio: TButton
    Left = 128
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = btnAceptarRadioClick
  end
end
