#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOREMS "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Voluptatum aspernatur quia quisquam cumque, commodi officiis porro, ex id ab quidem nemo vitae quas impedit. Similique molestias itaque repellendus, voluptatem porro doloremque expedita nobis rerum. Saepe rem consequuntur incidunt quibusdam? Voluptate quidem laborum eligendi ad incidunt odit illum doloremque inventore dolores!"
#define LOREMM "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Aperiam odio, recusandae quaerat ducimus omnis nostrum vitae dignissimos expedita iusto fugit est ipsam non natus pariatur ab sapiente delectus fugiat. Inventore, vel sit libero voluptatum facere repellendus, pariatur placeat in blanditiis labore ipsa excepturi nemo dolorum! Illo praesentium nam magni, incidunt sunt laudantium doloremque optio soluta ipsam quo aut maiores eius ipsum blanditiis assumenda numquam atque delectus non qui vitae. Veritatis assumenda porro vel quas beatae ipsa ex officia voluptate reprehenderit nam itaque quasi praesentium, dolore nisi eius tenetur obcaecati excepturi. Ducimus voluptatem quae fuga delectus dolore quasi vitae dolores quam odit ex! Corporis beatae modi debitis provident, architecto, accusantium animi reiciendis, consequatur sint eaque at temporibus fugiat cumque fuga accusamus."
#define LOREML "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Laboriosam, repellat ex! Expedita, reiciendis veniam alias nostrum dolor ullam qui, molestias, libero modi nesciunt nemo perferendis dicta explicabo dolorem saepe est aperiam inventore corporis exercitationem voluptatibus! Atque perspiciatis eaque sequi quam, deleniti, ullam minus dolores fugit corporis nulla similique maxime amet asperiores qui, corrupti itaque. Error dignissimos blanditiis molestiae veritatis iusto voluptate, possimus voluptas totam, quae temporibus repudiandae ad a aperiam eligendi sunt consectetur obcaecati dolores rerum amet sint. Sint ipsam et, aliquam nostrum dolor cum? Cum eum excepturi deserunt, dolore fuga soluta corrupti id, neque vero, laudantium ratione! A, cupiditate vitae rerum soluta itaque odio eius saepe voluptate distinctio, maiores dolore nostrum at dolor asperiores voluptas porro deserunt architecto odit. Deserunt delectus architecto optio minus quod repellendus quasi totam non, illum consequuntur, corrupti ad inventore eum itaque ea facilis, a assumenda iusto voluptate quos amet nostrum? Temporibus, iste aliquam! Ipsum autem iste ea aliquam odit libero, fuga doloribus, minus quibusdam incidunt nesciunt optio culpa aspernatur in ipsa dignissimos molestiae quisquam consequatur maiores sapiente! Quo, vitae sequi maiores corrupti culpa rem ipsum numquam laborum iste totam pariatur iure autem ex! Animi pariatur porro quidem fugiat eius! Cum accusamus et officiis eligendi eos quaerat cumque deleniti voluptate, non maiores ut voluptas vitae tempora officia quibusdam amet at. Iste, debitis mollitia? Cum fugiat eaque libero corporis ratione esse iusto modi accusamus quas laborum assumenda nihil at ad alias ipsam, repellendus magni earum adipisci velit? Esse provident impedit itaque consequatur, laudantium vitae architecto eos!"
#define SIZES 387
#define SIZEM 889
#define SIZEL 1845

void argument_error();

int main(int argc, char* argv[])
{
    // init
    FILE* out = stdout;
    // prepare paragraphs
    char* loremS = malloc(SIZES + SIZEM + SIZEL);
    char* loremM = loremS + SIZES;
    char* loremL = loremM + SIZEM;
    memcpy(loremS, LOREMS, SIZES);
    memcpy(loremM, LOREMM, SIZEM);
    memcpy(loremL, LOREML, SIZEL);
    char* lorem = loremM;

    // args reading
    for (int i=1 ; i < argc ; i++) {
        char* arg = argv[i];
        while (*arg) {
            switch (*arg) {
            case 's':
                lorem = loremS;
                break;
            case 'm':
                lorem = loremM;
                break;
            case 'l':
                lorem = loremL;
                break;
            case 'e':
                out = stderr;
            case '-':
                break;
            default:
                argument_error();
                return 1;
            }
            arg++;
        }
    }

    // write lorem on out stream
    fprintf(out, "%s\n", lorem);

    // return
    return 0;
}

void argument_error()
{
    fprintf(stderr, "[ARGUMENT ERROR]\n");
    fprintf(stderr, "The only accepted options is [s, m, l, e]\n");
}