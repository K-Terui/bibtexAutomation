# bibファイルの雑誌名，会議名を自動で略称に変更したい
bibファイルを読み込んで雑誌名等を略称に変更し，前置詞も消去することが可能です

## 実行例
初めに，編集したいbibファイルがあるディレクトリに移動してください．

ディレクトリを移動したら，そこにこのプログラムを保存してください．

このプログラムはC言語で記述されています．実行前にコンパイルしてください
``` power shell
$ gcc -o main main.c
```

コンパイルしたら実行します
``` power shell
$ ./main
```

つづいて，入力ファイル名と出力ファイル名の入力をしてください．ここではinput.bibを入力し，output.bibを出力するとします．
``` power shell
$ 入力ファイル名を入力してください: input.bib
$ 出力ファイル名を入力してください: output.bib
```

以上の手順により，雑誌名や会議名を略称に変更可能です．

実際にプログラムを動かすと以下のようになります．
``` bib
%%%%% input.bib %%%%%
@article{thornburg2016performance,
  title={Performance analysis of outdoor mmWave ad hoc networks},
  author={Thornburg, Andrew and Bai, Tianyang and Heath, Robert W},
  journal={IEEE Transactions on Signal Processing},
  volume={64},
  number={15},
  pages={4065--4079},
  year={2016},
  publisher={IEEE}
}
@inproceedings{polese2017tcp,
  title={TCP in 5G mmWave networks: Link level retransmissions and MP-TCP},
  author={Polese, Michele and Jana, Rittwik and Zorzi, Michele},
  booktitle={2017 IEEE conference on Computer Communications Workshops (INFOCOM WKSHPS)},
  pages={343--348},
  year={2017},
  organization={IEEE}
}
```
``` bib
%%%%% output.bib %%%%%
@article{thornburg2016performance,
 title={Performance analysis of outdoor mmWave ad hoc networks},
 author={Thornburg, Andrew and Bai, Tianyang and Heath, Robert W},
 journal={IEEE Trans. Signal Process.},
 volume={64},
 number={15},
 pages={4065--4079},
 year={2016},
 publisher={IEEE}
}
@inproceedings{polese2017tcp,
 title={TCP in 5G mmWave networks: Link level retransmissions and MP-TCP},
 author={Polese, Michele and Jana, Rittwik and Zorzi, Michele},
 booktitle={2017 IEEE Conf. Computer Commun. Workshops (INFOCOM WKSHPS)},
 pages={343--348},
 year={2017},
 organization={IEEE}
}
```

## 注意書き
このプログラムでは，IEEE Reference Guideを参照し略語リストを作成しています．各自追記してください
前置詞は on in of にしか対応していません．各自必要に応じて追記してください．
実行例は以下にまとめました．
