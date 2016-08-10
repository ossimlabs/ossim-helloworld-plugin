//*******************************************************************
//
// License:  LGPL
//
// See LICENSE.txt file in the top level directory for more details.
//
// Author: Garrett Potts
//*******************************************************************
//  $Id$
#include <ossim/plugin/ossimSharedObjectBridge.h>
#include <ossim/plugin/ossimPluginConstants.h>


namespace ossimplugins
{
   static void setDescription(ossimString& description)
   {
      description = "OSSIM HelloWorld Plugin\n\n";
   }


   extern "C"
   {
      ossimSharedObjectInfo  myInfo;
      ossimString theDescription;
      std::vector<ossimString> theObjList;
      const char* getDescription()
      {
         return theDescription.c_str();
      }
      int getNumberOfClassNames()
      {
         return (int)theObjList.size();
      }
      const char* getClassName(int idx)
      {
         if(idx < (int)theObjList.size())
         {
            return theObjList[0].c_str();
         }
         return (const char*)0;
      }

      /* Note symbols need to be exported on windoze... */
      OSSIM_PLUGINS_DLL void ossimSharedLibraryInitialize(
         ossimSharedObjectInfo** info)
      {
         myInfo.getDescription = getDescription;
         myInfo.getNumberOfClassNames = getNumberOfClassNames;
         myInfo.getClassName = getClassName;

         *info = &myInfo;

         setDescription(theDescription);
      }

      /* Note symbols need to be exported on windoze... */
      OSSIM_PLUGINS_DLL void ossimSharedLibraryFinalize()
      {
      }

   }
}