# Gerenciamento de Biblioteca
## User Stories
### User Story 01:
<p>Como um leitor da biblioteca eu gostaria de buscar um livro para achar sua localização física.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Busca de um livro por título;</p>
<p>Busca deve retornar em qual estante e qual quarto está o livro, ou se está alugado;</p>
<p>Busca deve retornar todas as informações do livro (título, autor);</p>
<p>Alugar um livro deve alterar a situação dele de forma que identifique que está locado e por quem ele foi locado;</p>

### User Story 02:
<p>Como um usuário Premium da biblioteca eu gostaria de locar quantos livros eu quiser.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número ilimitado de livros sem gerar erros;</p>

### User Story 03:
<p>Como um usuário Premium da biblioteca eu gostaria de ter acessos a livros, mesmo que limitado, sem ter que pagar pela minha conta.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número limitado de livros sem gerar erros;</p>
<p>Não permitir locação de livros acima do limite;</p>


### User Story 04:
<p>Como um organizador da biblioteca eu gostaria de registrar um novo leitor para que ele possa utilizar a biblioteca;</p>
<p><b>Critérios de aceitação:</b></p> 
<p>O novo usuário tem que ter nome;</p>
<p>Uma ID de usuário deve ser gerada;</p>
<p>Deve-se informar ao sistema se o usuário pode também fazer o papel de organizador ou só de leitor;</p>

## Cartões CRC:

<table>
  <tr>
    <th>Classe:  Usuário</th>
    <th> </th>
  </tr>
  <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Nome</td>
    <td>Organizador</td>
  </tr>
  <tr>
    <td>Lista de Livros Alugados</td>
    <td>Premium</td>
  </tr>
   <tr>
    <td>Lista de Livros Alugados</td>
    <td>Livro</td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Free</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Premium</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Organizador</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td> 
  </tr>
  <tr>
    <td>Username </td>
    <td> </td>
  </tr>
  <tr>
    <td>Registrar Usuário </td>
    <td> </td>
  </tr>
</table>
<table>
  <tr>
    <th>Classe:  Livro</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Título </td>
    <td>Premium </td>
  </tr>
  <tr>
    <td>Autor </td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Localização </td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Locado Por</td>
    <td> </td>
  </tr>
</table>
