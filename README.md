# MinWin32Exec2024

2024-11-24現在、Win32 x64構成で最小の実行可能バイナリを作成する実験。

## 方針

- Cランタイムライブラリの排除
- ビルドオプションを設定して不要なデータの生成を抑止

## 道具立て

- Visual Studio 2022 (v143)
- Windows SDK 10.0.26100.0

## プロジェクト設定

### カスタムエントリポイント

カスタムエントリポイント関数を定義して、Cランタイムライブラリの初期化を省略する。  
Win32プログラムでは一般的に、実行ファイルがメモリ上に読み込まれた後にエントリポイント関数から実行を開始する。Cランタイムライブラリが用意した既定のエントリポイント関数はライブラリを初期化した後に`main`または`WinMain`関数を呼び出す。自前のエントリポイント関数を用意することでライブラリの初期化を省略することができる。  
エントリポイント名は既定では`mainCRTStartup`や`WinMainCRTStartup`であるが、コンパイラオプション`/ENTRY:function`で指定できる。

### コンパイラオプション

| option | value |
| - | - |
| C++の例外を有効にする(/EH) | いいえ |
| SDLチェック(/SDL) | いいえ(/sdl-) |
| セキュリティチェック(/GS) | 無効(/GS-) |
| 最適化(/O) | 最大最適化(サイズを優先)(/O1) |

### リンカオプション

| option | value |
| - | - |
| マニフェストの生成(/MANIFEST) | いいえ(/MANIFEST:NO) |

## 結果

|バイナリ|サイズ (bytes)|
|-|-|
|MinWin32Con.exe|3072|
|MinWin32Gui.exe|2560|
