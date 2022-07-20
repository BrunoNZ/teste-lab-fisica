# teste-lab-fisica

## Objetivo:
Baixar 10 séries de dados Pluviometricos (https://www.snirh.gov.br/hidroweb/serieshistoricas) e, para cada série, gerar os resultados descritos abaixo e salvá-los de forma que seja possível plotar os resultados individualmente após a execução.

## Resultados:
  1. Média diária. Ex.: Média do dia 1 entre todos os meses/anos, média do dia 2, ...
  2. Média mensal de cada período. Ex.: Média de todos os dias do período 01/2022, média do período 02/2022, ...
  3. Média mensal. Ex.: Média do mês 01 de todos anos, média do mês 02, ...
  4. (bônus) Média móvel diária. Ex.: Média dos dias [1,2,3] da série completa (do primeiro ao último dia, em ordem cronológica), média dos dias [2,3,4], ...

## Bônus:
Plotar os resultados usando o [gnuplot](http://www.gnuplot.info/), cada um em uma figura. O diretório `ex_plot` contém um exemplo de uma plotagem simples.

## Informações importantes:
  * Os valores de `chuva` são válidos quando o valores correspondentes de `chuva_status` forem igual a 1.
  * A organização das variáveis pode ser alterada a vontade.
  * O máximo de linhas (256) foi estipulado apenas a fim de simplificar a leitura dos arquivos.