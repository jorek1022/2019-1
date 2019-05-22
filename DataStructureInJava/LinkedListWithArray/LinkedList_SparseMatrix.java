/*
	HW192
	20160182
	Lee Roje
*/

import java.util.*;

import javax.lang.model.util.ElementScanner6;

import com.sun.javafx.geom.Matrix3f;

// offset

/**
 * SparseMatrix Class
 * 
 */


// ---------- SparseMatrix class -------------
class SparseMatrix extends LinkedMatrix {
	SparseMatrix() { } // SparseMatrix constructor. 


	boolean AddOneElement(final int r, final int c, final int  v) {
        if (v == 0) return true;
        
        MatrixNode newNode = new MatrixNode(r,c,v);
        
        if (row[r] == null && col[c] == null){
            row[r] = newNode;
            col[c] = newNode;
        }
        else if (row[r] == null && col[c] != null) {
            row[r] = newNode;
            MatrixNode cbefore = col[c];
            
            if (cbefore.row < r) {
                while (cbefore.down != null){
                    if (cbefore.down.row >= r)
                        break;
                    cbefore = cbefore.down;
                }
                if (cbefore.down == null) {
                    cbefore.down = newNode;
                }
                else {
                    newNode.down = cbefore.down;
                    cbefore.down = newNode;
                }
            }
            else if (cbefore.row > r) {
                newNode.down = cbefore;
                cbefore = newNode;
            }
           
        }
        else if (row[r] != null && col[c] == null){
            col[c] = newNode;
            MatrixNode rbefore = row[r];

            if (rbefore.col < c) {
                while (rbefore.next != null) {
                    if (rbefore.next.col >= c) 
                        break;
                    rbefore = rbefore.next;
                }
                if (rbefore.next == null) {
                    rbefore.next = newNode;
                }
                else {
                    newNode.next = rbefore.next;
                    rbefore.next = newNode;
                }
            }
            else if (rbefore.col > c) {
                newNode.next = rbefore;
                rbefore = newNode;
            }
            
        }
        else {
            MatrixNode rbefore = row[r];
            MatrixNode cbefore = col[c];

            if (rbefore.col == c || cbefore.row == r)
                return false;
            if (rbefore.col < c && cbefore.row < r) {
                while (rbefore.next != null) {
                    if (rbefore.next.col >= c)
                        break;
                    rbefore = rbefore.next;
                }
                while (cbefore.down != null) {
                    if (cbefore.down.row >= r)
                        break;
                    cbefore = cbefore.down;
                }

                if (rbefore.next == null) rbefore.next = newNode;
                else {
                    if (rbefore.next.col == c) return false;
                    else {
                        newNode.next = rbefore.next;
                        rbefore.next = newNode;
                    }
                }

                if (cbefore.down == null) cbefore.down = newNode;
                else {
                    if (cbefore.down.row == r) return false;
                    else {
                        newNode.down = cbefore.down;
                        cbefore.down = newNode;
                    }
                }
            }
            else if (rbefore.col < c && cbefore.row > r) {
                while (rbefore.next != null) {
                    if (rbefore.next.col >= c)
                        break;
                    rbefore = rbefore.next;
                }
                if (rbefore.next == null) rbefore.next = newNode;
                else {
                    if (rbefore.next.col == c) return false;
                    else {
                        newNode.next = rbefore.next;
                        rbefore.next = newNode;
                    }
                }
                //------ col ------
                newNode.down = col[c];
                col[c] = newNode;
            }
            else if (rbefore.col > c && cbefore.row < r) {
                while (cbefore.down != null) {
                    if (cbefore.down.row >= r)
                        break;
                    cbefore = cbefore.down;
                }
                if (cbefore.down == null) cbefore.down = newNode;
                else {
                    if (cbefore.down.row == r) return false;
                    else {
                        newNode.down = cbefore.down;
                        cbefore.down = newNode;
                    }
                }
                //----- row -----
                newNode.next = row[r];
                row[r] = newNode;
            }
            else if (rbefore.col > c && cbefore.row > r) {
                newNode.down = col[c];
                col[c] = newNode;
                newNode.next = row[r];
                row[r] = newNode;
                
            }
        }

		return true;
	}



	boolean Delete(final int r, final int c) {
        if (row[r] == null || col[c] == null) return false;
        else {
            MatrixNode rbefore = row[r];
            MatrixNode cbefore = col[c];

            if (rbefore.col == c && cbefore.row == r) {
                row[r] = rbefore.next;
                col[c] = cbefore.down;
                return true;
            }
            else if (rbefore.col == c && cbefore.row < r) {
                row[r] = rbefore.next;

                while (cbefore.down != null) {
                    if (cbefore.down.row >= r)
                        break;
                    cbefore = cbefore.down;
                }
                if (cbefore.down.row == r){
                    MatrixNode temp = cbefore.down;
                    cbefore.down = temp.down;
                    temp = null;
                }
            }
            else if (rbefore.col < c && cbefore.row == r) {
                col[c] = cbefore.down;

                while (rbefore.next != null) {
                    if (rbefore.next.col >= c)
                        break;
                    rbefore = rbefore.next;
                }

                if (rbefore.next.col == c) {
                    MatrixNode temp = rbefore.next;
                    rbefore.next = temp.next;
                    temp = null;
                }
            }
            else if (rbefore.col < c && cbefore.row < r) {
                while (rbefore.next != null) {
                    if (rbefore.next.col >= c)
                        break;
                    rbefore = rbefore.next;
                }
                if (rbefore.next == null) return false;
                else {
                    if (rbefore.next.col == c) {
                        MatrixNode temp = rbefore.next;
                        rbefore.next = temp.next;
                        temp = null;
                    }
                    else {
                        return false;
                    }
                }
                //----- col ------
                while (cbefore.down != null) {
                    if (cbefore.down.row >= r)
                        break;
                    cbefore = cbefore.down;
                }            
                if (cbefore.down == null) return false;
                else{
                    if(cbefore.down.row == r) {
                        MatrixNode temp = cbefore.down;
                        cbefore.down = temp.down;
                        temp = null;
                    }
                    else {
                        return false;
                    }
                }    
            }
            else {
                return false;
            }
        }
		return true;
	}

	SparseMatrix Add(SparseMatrix b) {
		
		SparseMatrix c = new SparseMatrix();
		c.Init(rows, cols);

		int rPos = 1;

		while(rPos <= rows)
		{
			MatrixNode abefore = row[rPos];
			MatrixNode bbefore = b.row[rPos];

			if (abefore == null && bbefore == null){}
			else if (abefore != null && bbefore == null){
				while (abefore != null){
					c.AddOneElement(abefore.row, abefore.col, abefore.value);
					abefore = abefore.next;
				}
			}
			else if (abefore == null && bbefore != null){
				while (bbefore != null){
					c.AddOneElement(bbefore.row, bbefore.col, bbefore.value);
					bbefore = bbefore.next;
				}
			}
			 // abefore != null && bbefore != null
			else{
				while(abefore != null && bbefore != null){
					if (abefore.col == bbefore.col){
						c.AddOneElement(abefore.row, bbefore.col, abefore.value + bbefore.value);
						abefore = abefore.next;
						bbefore = bbefore.next;
					}
					else if (abefore.col < bbefore.col){
						c.AddOneElement(abefore.row, abefore.col, abefore.value);
						abefore = abefore.next;
					}
					else{
						c.AddOneElement(bbefore.row, bbefore.col, bbefore.value);
						bbefore = bbefore.next;
					}
				}
				if (abefore == null && bbefore != null){
					while(bbefore != null){
						c.AddOneElement(bbefore.row, bbefore.col, bbefore.value);
						bbefore = bbefore.next;
					}
				}
				else if (abefore != null && bbefore == null){
					while (abefore != null){
						c.AddOneElement(abefore.row, abefore.col, abefore.value);
						abefore = abefore.next;
					}
				}	
			}
			rPos++;
		} // big while end
		return c;
	
	}
}


