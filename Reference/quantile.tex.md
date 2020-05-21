# 四分位，外れ値について

## 四分位(Quantile)とは

$N$個のデータを標本化（抽出）したとき，その$N$個はそれぞれ数値を持っていて，その数値で昇順に並びかえる．

並べたデータの$k\dfrac{N+1}{4}$番目の数値を第$k$四分位(k-th quantile;${\rm Q}k$)という．

- 特に，第2四分位は別名「中央値（メジアン;median）」とも言う．
- もし上記の「?番目」の「?」が2.5など非整数の場合は，2番目の値と 3番目の値の平均（足して2で割る）とする．

例えば，

|subject|value|
|---|---|
|1|3|
|2|5|
|3|5|
|4|6|
|5|1|
|6|3|
|7|0|
|8|9|
|9|2|
|10|20|
|11|10|

のような$N=11$の標本を得たとき，valueを昇順に並び変えると

|#|subject|value|
|---|---|---|
|1|7|0|
|2|5|1|
|3|9|2|
|4|1, 6|3|
|6|2, 3|5|
|8|4|6|
|9|8|9|
|10|11|10|
|11|10|20|

N=11なので，Q1は(11+1)/4=3番目，Q2は6番目，Q3は9番目の値である．すなわち，

- Q1 : 2
- Q2 (median) : 5
- Q3 : 9

となる．

ところで，メジアン（中央値）は，標本の分布の中心を表す代表値であるが，似たような代表値で頻出するのは平均値（ミーン;mean）である．

$$
{\rm mean} = \frac{1}{N}\sum_{i=1}^{N} {\rm value}(i)  
$$

今回の標本であれば，meanはおおよそ$5.8$である．今回はmedianとmeanのどちらか標本の分布の中心を表す代表値としてふさわしいだろうか．
ふさわしさは，標本の抽出元の母集団の分布の中心（期待値;Expectation）への近さで表される．

では，今回の標本の抽出元の母集団の分布はどんな分布しているんでしょう？

- 今回の標本には現れなかったが，母集団には負の値も含まれるのでしょうか
- 今回の標本には現れなかったが，母集団には小数も現れるのでしょうか
- 今回の標本は，0から20の間にありますが，母集団の範囲も同じでしょうか？
- 11個抽出した場合にいつでも上のメンバーになるような分布でしょうか

「わからない」が正直なところだが，ここで大きな妄想が入ります．「自然現象は正規分布する！」本当かどうかは怪しいが，わりと当たっている．
すなわち，どこかの値の周りにデータが集まりやすく，上側・下側に対称的にデータが広がって分布している．

では今回の標本はどうか．さきほどの表は，昇順にvalueの階級値ごとにデータの個数を並べると

|value|freq|*|
|---|---|---|
|0|1|*|
|1|1|*|
|2|1|*|
|3|2|**|
|4|0||
|5|2|**|
|6|1|*|
|7|0||
|8|0||
|9|1|*|
|10|1|*|
|11|0||
|12|0||
|13|0||
|14|0||
|15|0||
|16|0||
|17|0||
|18|0||
|19|0||
|20|1|*|

3列目は個数を*の数で表していて，横向きの棒グラフ（ヒストグラム）と思えばいい．正規分布から標本化したと考えると，3から5あたりに中心があって，分布の幅（標準誤差；標本の標準偏差）は，．．．

ここで第1四分位(Q1)以下の値をもつデータは，全体の$\dfrac{1}{4}=25\%$以下であり，同様に，Q2以下の値をもつのは$50\%$以下，Q3以下の値をもつのは$75\%$以下と言えるので，Q1とQ2（中央値）の間には$25\%$，Q2とQ3の間にも$25\%$，すなわちQ2を含むQ1からQ2までの範囲の値をもつデータが全体の中心的な$50\%$といえる．

実は，標準偏差$s$というのは 平均を$m$としたとき，$m-s$から$m+s$にデータの約$68\%$が含まれるような値だ（本当に正規分布から標本化したら）．

今回は正規分布してそうだけどわからないので，データの$50\%$を含む下限と上限をQ1とQ2として，標準偏差的なものを$\frac{{\rm Q3}-{\rm Q1}}{2}$と考えればよい．この分子${\rm Q3}-{\rm Q1}$を「四分位範囲」(Interval of Quantile Range)と呼ぶ．

今回の標本では，

$$ IQR = Q3-Q1 = 9-2 = 7 $$ 

## 外れ値

さらに，正規分布では，平均から標準偏差の3倍以上離れるとほとんどデータが存在しないはず(0.005%)で，そこにあらわれるデータは外れ値（アウトライアー;Outlier）といって同じ母集団から標本化したと言えない，もしくはノイズと考えられる．今回の場合は，その「平均から標準偏差の3倍離れた値」を「中央値から四分位範囲の2倍離れた値」や「1Qや3Qから1.5 IQR離れた値」と考える．

その値は，今回の標本から求めると，

$$
Q1-1.5 IQR = 2-1.5\times 7 = -8.5\\
Q3+1.5 IQR = 9+1.5\times 7 = 19.5
$$

となり，subject 10 の value 20　という値は外れ値となる．

## 箱ひげ図(boxcar graph)

これら四分位で分布を表す図が箱ひげ図(boxcar graph)である．

上フタをQ3，中央をQ2，下フタをQ1の位置とした箱を書き，それに加えて
上ヒゲとして，外れ値を除いた最大値，
下ヒゲとして，外れ値を除いた最小値の位置に書いたものである．

## 2つの標本に差があるかどうか

2つの標本に差があるかどうかは，良く知られた「2群の平均値の差の検定」（ウェルチのt検定）で検定できます．
ただし，それぞれの標本の母集団が正規分布していなければいけません．また，それぞれの標本のサイズが小さいと検定に信頼がもてません．

今回は，男女合わせて12人のデータであり，性別ごとに分けた2つの標本のサイズはとても小さいです．母集団（日本人や長崎県や長崎大の男全体や女全体）は正規分布していると想定できますが，今回の数人の標本では，標本の分布と考えにくいので，標本平均や分散を母集団の平均や分散の推定値にはできません．

標本のサイズが小さいとき，分布をあらわすのが四分位です．第2四分位（中央値）は平均値のような代表値，四分位範囲は分散のような分布の幅をあらわす代表値です．第1四分位から第3四分位の範囲に標本の半分が入ります．なので，それぞれの標本のこの範囲が重ならないほど標本に差があるといえます．

つまり，女性の第3四分位$Q3_f$が男性の第1四分位$Q1_m$より下であれば，男性と女性で差があるといっていいでしょう．また，その差の大きさは，
$Q1_m-Q3_f$で表されますが，この値だけ見ても大きいと考えるべきか小さいと考えるべきかわからないので，この差が四分位範囲の何倍か考えるとおおよそ0~1の間になって，判断しやすくなります．

$$ D = \frac{Q1_M-Q3_f}{\frac{IQR_m+IQR_f}{2}} $$

ちなみにこの$D$は，勝手に私が考えてみたものですので「例えばのはなし」と思ってください．
