import java.util.ArrayList;

/**
 * Cracking the coding interview 7.9
 * Explain the data structures and algorithms that you would use to design an in-memory
 * file system Illustrate with an example in code where possible
 * Created by petrutrimbitas on 26/12/13.
 */


class DataBlock {}
class Folder extends DataBlock{}
class File extends DataBlock{}

class FileTreeNode {
    private ArrayList<FileTreeNode> subFolders;
    private ArrayList<DataBlock> files;
    DataBlock db;
    public FileTreeNode() {
        subFolders=new ArrayList<FileTreeNode>();
    }
    void createFolder(String name) {
        Folder nf=new Folder();
        FileTreeNode nn=new FileTreeNode();
        subFolders.add(nn);
        files.add(nf);
    }
    public FileTreeNode find(String name) { return null;}
}

public class FileSystem {
}
