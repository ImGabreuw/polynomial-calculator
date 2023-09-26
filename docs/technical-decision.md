# Decisões técnicas

- Utilização de arquivos `.h` para prototipagem de funções e estruturas.

  - A adoção dessa prática proporciona uma séries de benefícios, entre elas:

    1. **Modularidade**: permitem dividir o código-fonte em partes menores e com objetivos bem definidos;
    2. **Reutilização de código**: permitem a reutilização de funções e estruturas em diferentes partes do programa, sem precisar copiar e colar a suas definições em cada local de uso.
    3. **Compilação mais rápida**: ao fazer alterações em um arquivo `.c`, apenas esse arquivo precisa ser recompilado, desde que não haja alterações nas declarações no arquivo de cabeçalho. Com isso, economiza tempo de compilação.
       > Fonte: [Stack Exchange](https://softwareengineering.stackexchange.com/questions/56215/why-can-you-have-the-method-definition-inside-the-header-file-in-c-when-in-c-y#:~:text=In%20C%2C%20if%20you%20define,be%20exported%20for%20the%20function.)

  - Utilização de `#define` guards:

    A inclusão de `#define` guards em todos os arquivos de cabeçalho é uma prática recomendada para evitar a inclusão múltipla acidental.

    O formato do nome do símbolo deve ser: `<PROJECT>_<PATH>_<FILE>_H_`

    > Fonte: [Google Style Guide](https://google.github.io/styleguide/cppguide.html#The__define_Guard)

  - Incluir tudo que for necessária

    Se um arquivo precisa de um símbolo definido em outro lugar, inclua diretamente o cabeçalho desse símbolo. Evite inclusões desnecessárias e não confie em inclusões transitivas.

    > Fonte: [Google Style Guide](https://google.github.io/styleguide/cppguide.html#Include_What_You_Use)

  - Nomes e ordem das inclusões

    Inclua os cabeçalhos na seguinte ordem:

    1.  Cabeçalho relacionado (implementação do cabeçalho no arquivo `.c`);
    2.  Cabeçalhos do sistema C (cabeçalhos entre colchetes com a extensão `.h`, por exemplo, `<unistd.h>`, `<stdlib.h>`);
    3.  Cabeçalhos da biblioteca padrão C++;
    4.  Cabeçalhos de outras bibliotecas;
    5.  Cabeçalhos do projeto.

    > Fonte: [Google Style Guide](https://google.github.io/styleguide/cppguide.html#Names_and_Order_of_Includes)
