using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectPooler : MonoBehaviour
{
    public GameObject theObject;
    public int pooledAmnt;

    List<GameObject> theObjects;

    // Start is called before the first frame update
    void Start()
    {
        theObjects = new List<GameObject>();
        int i = 0;

        // initialize object list
        while(i < pooledAmnt)
        {
            GameObject myObject = (GameObject)Instantiate(theObject);
            myObject.SetActive(false);
            theObjects.Add(myObject);
            i = i + 1;
        }
        
    }

    public GameObject GetPObject()
    {
        int i = 0;
        while(i < theObjects.Count)
        {
            if(theObjects[i].activeInHierarchy == false)
            {
                return theObjects[i];
            }
            i++;
        }

        GameObject myObject = (GameObject)Instantiate(theObject);
        myObject.SetActive(false);
        theObjects.Add(myObject);
        return myObject;

    }
}
