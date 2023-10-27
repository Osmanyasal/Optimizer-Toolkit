#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 26 22:34:56 2023

@author: osman.yasal

Purpose
===========

Read all <vendor>_<pmu>_events.h files in libpfm4 and convert them to 
compatible c++ class higherarchy for effective usage.

"""
import sys
import os

EVENT_FILE_EXTENSION = ".hh"
EVENT_FILE_PATH = "../core/events/"

HEADERS = "#include <cstdint>\n\n"
NAMESPACE_BEGIN = "namespace optkit_{}{{\n\t"
EVENT_CLASS_BEGIN = "enum class {} : uint64_t {{\n\t\t"
PMU_EVENT = "{} = {}, // {}"
EVENT_CLASS_END = "};"
NAMESPACE_END = "};"

def process_event_dic(event_dict,event_pe): 
    vendor_name = event_pe.split("_")[0]
    pmu_name = event_pe.replace(vendor_name + "_" ,"").replace("_pe","")
    result = HEADERS + NAMESPACE_BEGIN.format(vendor_name) + EVENT_CLASS_BEGIN.format(pmu_name)
    
    event_counter = {}    
    for event in event_dict[event_pe]: 
        members = event.split(",")
        event_name = next((item for item in members if ".name" in item.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
        event_code = next((item for item in members if ".code" in item.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
        event_desc = next((item for item in members if ".desc" in item.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
        event_umasks = next((item for item in members if ".umasks" in item.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
        
        if event_counter.get(event_name,0) == 0: ## first encounter to that event_name
            event_counter[event_name] = 1
            result += PMU_EVENT.format(event_name,event_code,event_desc) + "\n\t\t"
            
        if len(event_umasks) > 0:
            for mask in event_dict[event_umasks]:
                mask_members = mask.split(",")    
                mask_name = next((mask_val for mask_val in mask_members if ".uname" in  mask_val.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
                mask_code = next((mask_val for mask_val in mask_members if ".ucode" in mask_val.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
                mask_desc = next((mask_val for mask_val in mask_members if ".udesc" in mask_val.replace(" ","")),"").split("=")[-1].replace("\"","").strip()
                result += PMU_EVENT.format(event_name + "_MASK_" + mask_name ,mask_code,mask_desc) + "\n\t\t"
 
            
    return result + EVENT_CLASS_END + NAMESPACE_END

if __name__ == "__main__": 

    if os.path.exists(EVENT_FILE_PATH+"/all_set"):
        os.remove(EVENT_FILE_PATH+"/all_set")

    if os.path.exists(EVENT_FILE_PATH+"/errors"):
        os.remove(EVENT_FILE_PATH+"/errors")

    event_dict = {}
    # Get command-line arguments
    event_files = sys.argv[1:]  # The first item in sys.argv is the script's name, so we start from the second item.

    if len(event_files) == 0:
        print("[ERROR]: Enter valid event files")
        sys.exit(1)
         
    for event_file in event_files:
        if not os.path.isfile(event_file):
            if os.path.exists(EVENT_FILE_PATH+"/all_set"):
                os.remove(EVENT_FILE_PATH+"/all_set")

            err_msg = f"[ERROR]: The file '{event_file}' does not exists!\n"
            print(err_msg)
            with open(EVENT_FILE_PATH+"/errors","a") as error_file:
                error_file.write(err_msg)

        else:  
            try:
                with open(event_file, 'r') as file:
                    lines = file.readlines()
                
                event_lines = ""
                event_pe= ""
                read_event_lines = False
                
                for line in lines:
                    line = line.strip()
                    if line.find("static") != -1:
                        while line.find("[]") == -1:
                            continue
                        word = [word for word in line.split() if word.find("[") != -1][0]
                        word = word[: word.find("[")]
                        if word.endswith("_pe"):
                            event_pe = word
                        event_dict[word] = []
                        read_event_lines = True
                    elif read_event_lines:
                        if line.endswith("},"):
                            event_lines += line
                            event_dict[word].append(event_lines.strip())
                            event_lines = ""
                        elif line.find("};") == -1:
                            event_lines += line
                        else:
                            read_event_lines = False
                
                ## do c++ class-enum_class conversion here based on the format
                vendor_name = event_pe.split("_")[0]
                vendor_folder = EVENT_FILE_PATH+"/"+vendor_name
                pmu_name = event_pe.replace(vendor_name + "_" ,"").replace("_pe","")
                if not os.path.exists(vendor_folder):
                    os.mkdir(vendor_folder)
                with open(vendor_folder+"/" + pmu_name + EVENT_FILE_EXTENSION, "w") as cpp_file:
                    class_higherachy = process_event_dic(event_dict,event_pe)
                    cpp_file.writelines(class_higherachy)

            except Exception as e:
                if os.path.exists(EVENT_FILE_PATH+"/all_set"):
                    os.remove(EVENT_FILE_PATH+"/all_set")
                with open(EVENT_FILE_PATH+"/errors", "a") as error_file:
                    error_file.write(str(e)+"\n")

    if not os.path.exists(EVENT_FILE_PATH+"/errors"):
        with open(EVENT_FILE_PATH+"/all_set", "a") as f:
            f.write("All SET!\n")

