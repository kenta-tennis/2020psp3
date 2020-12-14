# 課題3 レポート
35319024 篠隈健太


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明

19,21:変数を初期化する。

19~33:比較場所の文字を比較し、一致していたら次の文字を比較する。不一致なら比較開始位置を右に一つずらし、比較場所も先頭（0）にする。

42:不一致となった場合、文字毎にどれだけずらすかを計算するテーブルを用意する。

65:最初の比較場所をキー文字列の末尾にする。

67~111:キー文字列の末尾から前に向かって文字列を比較する。一致した場合、次の文字を比較する。不一致の場合、文字毎に決められた量だけ、比較に開始点をずらす。

## 出力結果

```
bb35319024@DESKTOP-N8LSJ1E MINGW64 ~/Desktop/2020psp3/k03 (develop)
$ ./k03
Force Search. Find keyword at:wind
On a dark deseart highway, cool wind in my hair.
wind
text= , key=w
key_index=7, index=3, a=0
On a dark deseart highway, cool wind in my hair.
    wind
text=a, key=w
key_index=11, index=7, a=0
On a dark deseart highway, cool wind in my hair.
        wind
text=d, key=w
text=d, key=i
text=d, key=n
text=d, key=d
BM Search. Find keyword at:k deseart highway, cool wind in my hair.
```

## 修正履歴

