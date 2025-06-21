import java.io.File;
/**
 *
 * @author decodigo
 */
public class Rename {
    public static void main(String[] args) {
        //Busca desde el número "busc" y aumenta "nBusc" para busar más
        String busc = "1";
        int nBusc = Integer.parseInt(busc);
        File oldfile = new File("C:/Test/Audios/Recording_0000 ("+busc+").m4a");

        //Renombra desde el número "reName" y aumenta "nRename" para renombrar más
        String reName = "0043";
        int nRename = Integer.parseInt(reName);
        File newfile;

        while(true ){//oldfile.exists()
            nRename++;
            reName = nRename +"";
            int l = reName.length();
            for(int i = 0; i < 4-l;i++){
                reName = "0" + reName;
            }//Convierte reName en un número de 4 dígitos rellenando en la izquierda con 0s

            //Genera el nuevo nombre y se lo cambia (puede cambiar la crapeta en la que estaba)
            newfile = new File("C:/Test/Audios2/miquelgo50-"+reName+".m4a");
            if (oldfile.renameTo(newfile)) {
                System.out.println("archivo renombrado");
            } else {
                System.out.println("error");
            }
            
            nBusc++;
            busc = nBusc +"";
            l = busc.length();
            for(int i = 0; i < 0-l;i++){
                busc = "0" + busc;
            }//Convierte reName en un número de ? dígitos rellenando en la izquierda con 0s
            oldfile = new File("C:/Test/Audios/Recording_0000 ("+busc+").m4a");
        }
         
    }
}