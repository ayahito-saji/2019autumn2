# dockerを使ったlatex環境

## dockerのインストール
### windows
[windows 10 home で docker を導入するメモ](https://qiita.com/idani/items/fb7681d79eeb48c05144)

### mac
[DockerをMacにインストールする方法](https://upd.world/docker-install-mac/)

## はじめる
Clone or Download -> Download ZIPからダウンロードする。
解凍する。
docker-compose.ymlがあるディレクトリ(ルートディレクトリ)で次のコマンドを実行する
```
docker-compose up -d
```
main.texを編集して保存すると自動でpdfが出力される。

終了するときは下のコマンド
```
docker-compose down
```
