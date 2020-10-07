# Codinoite

Grupo aberto de estudo para cadetes da 42sp.

Todas as quartas e sextas as 22h no canal do Discord referente ao projeto atual.

## Projeto Atual: [ft_printf](https://github.com/brunovmc/codinoite/tree/master/ft_printf)

```c
int	ft_printf(const char *str,...);
```
Recriando o printf.

### Conversões obrigatorias

```
cspdiuxX%
```

Flags

```
-0.*
```
e campo minimo de largura com todas as conversões


## Projetos Passados: [get_next_line](https://github.com/brunovmc/codinoite/tree/master/get_next_line)

```c
int	get_next_line(int fd, char **line);
```

Leia um arquivo de texto `fd` e guarde o valor de cada linha em `**line`

se chamada em loop `**line` deve conter o valor da proxima linha

a função deve retornar:

- (1) 	- se achar uma quebra de linha (\n)
- (0) 	- se chegar no fim do arquivo (\0)
- (-1)	- se houver um erro 
 
nota:

	codigo na master esta atrasado, procure o codigo mais recente outras branchs
	isso sera corrigido na proxima quarta-feira

******

## Projetos Futuros

1. ft_printf
2. ft_server


******

## Colabore

Envie uma DM para bvidigal#1295 no Discord para tornar-se colaborador(a)

### Instruções

Clonar o projeto

```
git clone https://github.com/brunovmc/codinoite.git
```
```
cd codinoite
```
Crie sua propria branch

```
git checkout -b [nome da sua branch]
```
Para conferir em que branch esta
```
git branch
```
Para mudar de branch
```
git checkout [nome da branch]
```
## Agradecimentos

[Laercio Candido](https://github.com/LaercioCandido)

...e todos que participaram dos encontros!

Muito Obrigado!
