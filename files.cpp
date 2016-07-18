#include "files.h"

Files::Files()
{

}

QString Files::load_file()
{
   QWidget *ventana_load = new QWidget;
   QString fileName = QFileDialog::getOpenFileName(ventana_load,"Open file",QDir::currentPath(),"XML (*.xml)");
   return fileName;
}

QString Files::save_file()
{
    QWidget *ventana_save = new QWidget;
    QString fileName = QFileDialog::getSaveFileName(ventana_save,"Save file","","XML (*.xml)");
    return fileName;
}

void Files::xml_reader(QString xml_file)
{
    qDebug()<<("xml_reader");
    QFile file(xml_file);
    file.open(QFile::ReadOnly);

    QDomDocument doc("mydocument");
    doc.setContent(&file);
    QDomElement docElem = doc.documentElement();

    parse_roads(docElem);
    parse_intersections(docElem);

    mycircuit->circuit_id.append(docElem.attributes().namedItem("id").nodeValue());
    mycircuit->circuit_road_list.append(road_list);
    mycircuit->circuit_intersection_list.append(intersection_list);

    file.close();
}

void Files::xml_writer(QString fileName)
{
    mycircuit->circuit_id=fileName.split("/").last().split(".xml").value(0);
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("circuit");
    xmlWriter.writeAttribute("id",mycircuit->circuit_id);

    xmlWriter.writeStartElement("roads");
    if(mycircuit->circuit_road_list.count()>0){
        for(int i=0;i<mycircuit->circuit_road_list.count();i++){ //write roads
            xmlWriter.writeStartElement("road");
            xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_id);
            for(int k=0;k<mycircuit->circuit_road_list.at(i)->road_path_list.count();k++){ //write paths
                xmlWriter.writeStartElement("path");
                xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_path_list.at(k)->path_id);
                xmlWriter.writeStartElement("parameters");
                for(int l=0;l<mycircuit->circuit_road_list.at(i)->road_path_list.at(k)->path_parameters.count();l++){
                    xmlWriter.writeStartElement("parameter");
                    xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_path_list.at(k)->path_parameters.at(l));
                    xmlWriter.writeAttribute("type",mycircuit->circuit_road_list.at(i)->road_path_list.at(k)->path_types.at(l));
                    xmlWriter.writeCharacters(mycircuit->circuit_road_list.at(i)->road_path_list.at(k)->path_values.at(l));
                    xmlWriter.writeEndElement();
                }
                xmlWriter.writeEndElement();
                xmlWriter.writeEndElement(); //paths_end
            }
            xmlWriter.writeStartElement("rails");
            if(mycircuit->circuit_road_list.at(i)->road_rail_list.count()>0){
                for(int r=0;r<mycircuit->circuit_road_list.at(i)->road_rail_list.count();r++){ //write rails
            xmlWriter.writeStartElement("rail");
            xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_rail_list.at(r)->rail_id);
            xmlWriter.writeStartElement("parameters");
            for(int s=0;s<mycircuit->circuit_road_list.at(i)->road_rail_list.at(r)->rail_parameters.count();s++){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_rail_list.at(r)->rail_parameters.at(s));
                xmlWriter.writeAttribute("type",mycircuit->circuit_road_list.at(i)->road_rail_list.at(r)->rail_types.at(s));
                xmlWriter.writeCharacters(mycircuit->circuit_road_list.at(i)->road_rail_list.at(r)->rail_values.at(s));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        }
            }
            xmlWriter.writeEndElement(); // rails_end

            xmlWriter.writeStartElement("signals");
            if(mycircuit->circuit_road_list.at(i)->road_signal_list.count()>0){
                for(int t=0;t<mycircuit->circuit_road_list.at(i)->road_signal_list.count();t++){ //write rails
            xmlWriter.writeStartElement("signal");
            xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_signal_list.at(t)->signal_id);
            xmlWriter.writeStartElement("parameters");
            for(int u=0;u<mycircuit->circuit_road_list.at(i)->road_signal_list.at(t)->signal_parameters.count();u++){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id",mycircuit->circuit_road_list.at(i)->road_signal_list.at(t)->signal_parameters.at(u));
                xmlWriter.writeAttribute("type",mycircuit->circuit_road_list.at(i)->road_signal_list.at(t)->signal_types.at(u));
                xmlWriter.writeCharacters(mycircuit->circuit_road_list.at(i)->road_signal_list.at(t)->signal_values.at(u));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        }
            }
            xmlWriter.writeEndElement(); //signals_end

            xmlWriter.writeEndElement(); //road_end
        }
    }
    xmlWriter.writeEndElement(); //roads_end

    xmlWriter.writeStartElement("intersections");
    if(mycircuit->circuit_intersection_list.count()>0){
        for(int j=0;j<mycircuit->circuit_intersection_list.count();j++){ //write intersections
            xmlWriter.writeStartElement("intersection");
            xmlWriter.writeAttribute("id",mycircuit->circuit_intersection_list.at(j)->intersection_id);
            xmlWriter.writeStartElement("parameters");
            for(int m=0;m<mycircuit->circuit_intersection_list.at(j)->intersection_parameters.count();m++){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id",mycircuit->circuit_intersection_list.at(j)->intersection_parameters.at(m));
                xmlWriter.writeAttribute("type",mycircuit->circuit_intersection_list.at(j)->intersection_types.at(m));
                xmlWriter.writeCharacters(mycircuit->circuit_intersection_list.at(j)->intersection_values.at(m));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement(); //intersection_end
        }
    }
    xmlWriter.writeEndElement(); //intersections_end

    xmlWriter.writeEndElement(); //circuit_end
    xmlWriter.writeEndDocument();
}

void Files::parse_roads(QDomElement docElem)
{
    QDomNodeList road_nodelist = docElem.elementsByTagName("road");
    if(road_nodelist.count()>0){
        for(int i=0;i<road_nodelist.count();i++){
            path_list.clear();
            rail_list.clear();
            signal_list.clear();
            Road *myroad = new Road;
            myroad->road_id.append(road_nodelist.at(i).attributes().namedItem("id").nodeValue());
            QDomNodeList road_childs_nodelist = road_nodelist.at(i).childNodes();
            if(road_childs_nodelist.count()>0){
                for(int i=0;i<road_childs_nodelist.count();i++){
                    if(road_childs_nodelist.at(i).nodeName()=="path")
                        parse_paths(road_childs_nodelist.at(i));
                    if(road_childs_nodelist.at(i).nodeName()=="rails")
                        parse_rails(road_childs_nodelist.at(i));
                    if(road_childs_nodelist.at(i).nodeName()=="signals")
                        parse_signals(road_childs_nodelist.at(i));
                }
            }
            myroad->road_path_list.append(path_list);
            myroad->road_rail_list.append(rail_list);
            myroad->road_signal_list.append(signal_list);
            road_list.append(myroad);
        }
    }
}

void Files::parse_intersections(QDomElement docElem)
{
    QDomNodeList intersection_nodelist = docElem.elementsByTagName("intersection");
    if(intersection_nodelist.count()>0){
        for(int i=0;i<intersection_nodelist.count();i++){
            Intersection *myintersection = new Intersection;
            myintersection->intersection_id.append(intersection_nodelist.at(i).attributes().namedItem("id").nodeValue());
            QDomNodeList intersection_parameters_nodelist = intersection_nodelist.at(i).firstChild().childNodes();
            if(intersection_parameters_nodelist.count()>0){
                for(int j=0;j<intersection_parameters_nodelist.count();j++){
                    myintersection->intersection_parameters.append(intersection_parameters_nodelist.at(j).attributes().namedItem("id").nodeValue());
                    myintersection->intersection_types.append(intersection_parameters_nodelist.at(j).attributes().namedItem("type").nodeValue());
                    myintersection->intersection_values.append(intersection_parameters_nodelist.at(j).toElement().text());
                }
            }
            intersection_list.append(myintersection);
        }
    }
}

void Files::parse_paths(QDomNode node)
{
    Path *mypath = new Path;
    mypath->path_id=node.attributes().namedItem("id").nodeValue();
    QDomNodeList path_parameters_nodelist = node.firstChild().childNodes();
    if(path_parameters_nodelist.count()>0){
        for(int i=0;i<path_parameters_nodelist.count();i++){
            mypath->path_parameters.append(path_parameters_nodelist.at(i).attributes().namedItem("id").nodeValue());
            mypath->path_types.append(path_parameters_nodelist.at(i).attributes().namedItem("type").nodeValue());
            mypath->path_values.append(path_parameters_nodelist.at(i).toElement().text());
        }
    }
    path_list.append(mypath);
}

void Files::parse_signals(QDomNode node)
{
    QDomNodeList signal_nodelist = node.childNodes();
    if(signal_nodelist.count()>0){
        for(int i=0;i<signal_nodelist.count();i++){
            Signal *mysgnl = new Signal;
            mysgnl->signal_id.append(signal_nodelist.at(i).attributes().namedItem("id").nodeValue());
            QDomNodeList signal_parameters_nodelist= signal_nodelist.at(i).firstChild().childNodes();
            if(signal_parameters_nodelist.count()>0){
                for(int k=0;k<signal_parameters_nodelist.count();k++){
                    mysgnl->signal_parameters.append(signal_parameters_nodelist.at(k).attributes().namedItem("id").nodeValue());
                    mysgnl->signal_types.append(signal_parameters_nodelist.at(k).attributes().namedItem("type").nodeValue());
                    mysgnl->signal_values.append(signal_parameters_nodelist.at(k).toElement().text());
                }
            }
            signal_list.append(mysgnl);
        }
    }
}

void Files::parse_rails(QDomNode node)
{
    QDomNodeList rail_nodelist = node.childNodes();
    if(rail_nodelist.count()>0){
        for(int j=0;j<rail_nodelist.count();j++){
            Rail *myrail = new Rail;
            myrail->rail_id.append(rail_nodelist.at(j).attributes().namedItem("id").nodeValue());
            QDomNodeList  rail_parameters_nodelist = rail_nodelist.at(j).firstChild().childNodes();
            if(rail_parameters_nodelist.count()>0){
                for(int l=0;l<rail_parameters_nodelist.count();l++){
                    myrail->rail_parameters.append(rail_parameters_nodelist.at(l).attributes().namedItem("id").nodeValue());
                    myrail->rail_types.append(rail_parameters_nodelist.at(l).attributes().namedItem("type").nodeValue());
                    myrail->rail_values.append(rail_parameters_nodelist.at(l).toElement().text());
                }
            }
            rail_list.append(myrail);
        }
    }
}
